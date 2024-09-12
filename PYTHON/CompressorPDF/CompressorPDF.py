"""
Importante: Esse código converte todas as paginas do PDF como imagem, incluindo as partes que são apenas texto, resultando assim em uma compressão maior.
Próximas melhorias: comprimir apenas imagens e preservar o texto
"""

import io
from PIL import Image
from pdf2image import convert_from_path
from reportlab.lib.pagesizes import A4
from reportlab.pdfgen import canvas
from reportlab.lib.utils import ImageReader
import fitz  # PyMuPDF

def convert_pdf_to_images(pdf_path):
    #Converte um arquivo PDF em uma lista de imagens e retorna uma lista de objetos de imagem.
    
    pdf_document = fitz.open(pdf_path)

    #print(range(pdf_document.page_count)) #verifica quantidade de paginas
    #page = pdf_document.load_page(5) #text = page.get_text() #print(text) #verifica o conteudo texto da page
    #page = pdf_document.load_page(5) #pixmap = page.get_pixmap() #print(pixmap) #verifica o conteudo imagem da page

    images = []
    for page_number in range(pdf_document.page_count):      
        page = pdf_document.load_page(page_number)
        pix = page.get_pixmap()
        img = Image.frombytes("RGB", [pix.width, pix.height], pix.samples)
        images.append(img)
    return images 
    
def compress_images(images, quality=20):
    """
    Comprime uma lista de imagens.
    
    Args:
        images (list): Uma lista de objetos de imagem.
        quality (int): A qualidade da compressão (0-100), padrão é 20.
    
    Returns:
        list: Uma lista de imagens comprimidas.
    """
    compressed_images = []
    for image in images:
        img_buffer = io.BytesIO()
        image.save(img_buffer, format="JPEG", quality=quality)
        img_buffer.seek(0)
        compressed_image = Image.open(img_buffer)
        compressed_images.append(compressed_image)
    return compressed_images

def insert_images_into_pdf(original_pdf_path, compressed_images, output_pdf_path):
    """
    Insere imagens comprimidas em um PDF e salva o novo PDF.
    
    Args:
        original_pdf_path (str): O caminho do arquivo PDF original.
        compressed_images (list): Uma lista de imagens comprimidas.
        output_pdf_path (str): O caminho onde o novo PDF será salvo.
    """
    pdf_document = fitz.open(original_pdf_path)
    c = canvas.Canvas(output_pdf_path, pagesize=A4)

    for page_number, compressed_image in enumerate(compressed_images):
        page = pdf_document.load_page(page_number)
        img_buffer = io.BytesIO()
        compressed_image.save(img_buffer, format="PNG")
        img_buffer.seek(0)
        c.drawImage(ImageReader(img_buffer), 0, 0, width=A4[0], height=A4[1])
        c.showPage()

    c.save()

if __name__ == "__main__":
    pdf_path = "/workspaces/Python_Projects_Portfolio/CompressorPDF/sample.pdf"  # caminho para o seu PDF
    extracted_images = convert_pdf_to_images(pdf_path)
    compressed_images = compress_images(extracted_images)
    insert_images_into_pdf(pdf_path, compressed_images, "/workspaces/Python_Projects_Portfolio/CompressorPDF/compressed_pdf.pdf")