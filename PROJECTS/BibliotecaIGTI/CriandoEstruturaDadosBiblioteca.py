import sqlite3
from faker import Faker
import random
from datetime import datetime, timedelta
fake = Faker()

# Função para executar o arquivo SQL
def executar_sql(arquivo_sql, banco_dados):
    # Conexão com o banco de dados
    conn = sqlite3.connect(banco_dados)
    cursor = conn.cursor()

    # Abre o arquivo SQL e executa cada comando
    with open(arquivo_sql, 'r') as sql_file:
        sql_script = sql_file.read()
        cursor.executescript(sql_script)

    # Salva as alterações e fecha a conexão
    conn.commit()
    conn.close()

# Função para inserir dados Ficticios nas tabelas
def insert_data_sql(banco_dados):
    # Conexão com o banco de dados
    conn = sqlite3.connect(banco_dados)
    cursor = conn.cursor()

    # Inserir países
    paises = [(1, 'Brasil'), (2, 'Estados Unidos'), (3, 'Reino Unido')]
    cursor.executemany('INSERT OR IGNORE INTO País (Código_do_País, Nome_do_País) VALUES (?, ?)', paises)
    # Inserir cidades
    cidades = [(1, 'São Paulo'), (2, 'Nova York'), (3, 'Londres')]
    cursor.executemany('INSERT OR IGNORE INTO Cidade (Código_da_Cidade, Nome_da_CIdade) VALUES (?, ?)', cidades)
    # Inserir gêneros literários
    generos_literarios = [(1, 'Ficção Científica'), (2, 'Fantasia'), (3, 'Romance')]
    cursor.executemany('INSERT OR IGNORE INTO Tipo_de_Gênero_Literário (Código_do_Gênero_Literário, Nome_do_Gênero_Literário) VALUES (?, ?)', generos_literarios)
    # Inserir gêneros
    generos = [(1, 'Masculino'), (2, 'Feminino'), (3, 'Não binário')]
    cursor.executemany('INSERT OR IGNORE INTO Tipo_de_Gênero (Código_do_Gênero, Nome_do_Gênero) VALUES (?, ?)', generos)
    # Inserir tipos de escolaridade
    escolaridades = [(1, 'Ensino Médio'), (2, 'Graduação'), (3, 'Pós-graduação')]
    cursor.executemany('INSERT OR IGNORE INTO Tipo_de_Escolaridade (Código_da_Escolaridade, Descrição_da_Escolaridade) VALUES (?, ?)', escolaridades)
    # Inserir tipos de estado civil
    estados_civis = [(1, 'Solteiro(a)'), (2, 'Casado(a)'), (3, 'Divorciado(a)')]
    cursor.executemany('INSERT OR IGNORE INTO Tipo_de_Estado_Cívil (Código_do_Estado_Cívil, Descrição_do_Estado_Cívil) VALUES (?, ?)', estados_civis)

    # Gerar e inserir dados fictícios para os Livros
    livros = []
    for _ in range(50):
        titulo = fake.sentence()
        ano = fake.year()
        edicao = random.randint(1, 10)
        isbn = fake.isbn13()
        editora = random.randint(1, 3)  # Supondo que existam 3 editoras
        genero_literario = random.randint(1, 3)  # Supondo que existam 3 gêneros literários
        autor = random.randint(1, 50)  # Supondo que existam 50 autores
        livros.append((titulo, ano, edicao, isbn, editora, genero_literario, autor))

    cursor.executemany('''INSERT OR IGNORE INTO Livro (Texto_do_Título, Ano_de_publicação, Número_da_Edição, Código_ISBN, idEditora, idGênero_Literário, idAutor)
                        VALUES (?, ?, ?, ?, ?, ?, ?)''', livros)
    
    # Gerar e inserir dados fictícios para os Autores
    autores = []
    for i in range(1, 51):
        nome_autor = fake.name()
        pais = random.randint(1, 3)  # Supondo que existam 3 países
        autores.append((i, nome_autor, pais))

    cursor.executemany('''INSERT OR IGNORE INTO Autor (Código_do_Autor, Nome_Completo_do_Autor, idPaís) VALUES (?, ?, ?)''', autores)

    # Gerar e inserir dados fictícios para as Editoras
    editoras = []
    for i in range(1, 4):  # Supondo que existam 3 editoras
        codigo_editora = fake.random_int(min=1000, max=9999)
        nome_editora = fake.company()
        pais = random.randint(1, 3)  # Supondo que existam 3 países
        cidade = random.randint(1, 3)  # Supondo que existam 3 cidades
        editoras.append((codigo_editora, nome_editora, pais, cidade))

    cursor.executemany('''INSERT OR IGNORE INTO Editora (Código_da_Editora, Nome_da_Editora, idPaís, idCidade) VALUES (?, ?, ?, ?)''', editoras)

    # Gerar dados fictícios para Usuários
    usuarios = []
    for _ in range(50):
        cpf = fake.random_int(min=10000000000, max=99999999999)  # CPF é um número de 11 dígitos
        nome_usuario = fake.name()
        data_nascimento = fake.date_of_birth(minimum_age=18, maximum_age=90)  # Entre 18 e 90 anos de idade
        genero = random.randint(1, 3)  # Supondo que existam 3 gêneros
        endereco_email = fake.email()
        endereco = fake.address()
        escolaridade = random.randint(1, 3)  # Supondo que existam 3 tipos de escolaridade
        estado_civil = random.randint(1, 3)  # Supondo que existam 3 tipos de estado civil
        telefone = fake.phone_number()
        usuario_ativo = random.randint(0, 1)  # 0 para inativo, 1 para ativo
        usuarios.append((cpf, nome_usuario, data_nascimento, genero, endereco_email, endereco, escolaridade, estado_civil, telefone, usuario_ativo))
    
    cursor.executemany('''INSERT OR IGNORE INTO Usuário (CPF, Nome_do_Usuário, Data_de_Nascimento, idGênero, Texto_do_Endereço_de_Email, Endereço, idTipo_de_Escolaridade, idTipo_de_Estado_Cívil, Numero_de_Telefone, Indicador_de_Usuário_Ativo)
                        VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)''', usuarios)
    
    # Gerar dados fictícios para Empréstimos
    emprestimos = []
    for _ in range(100):
        id_usuario = fake.random_int(min=10000000000, max=99999999999)  # CPF é um número de 11 dígitos
        id_exemplar = random.randint(1, 50)  # Supondo que existam 50 exemplares
        id_livro = random.randint(1, 50)  # Supondo que existam 50 livros
        momento_emprestimo = fake.date_time_between(start_date="-1y", end_date="now")
        data_devolucao = momento_emprestimo + timedelta(days=random.randint(7, 30))  # Devolução entre 7 e 30 dias depois do empréstimo
        emprestimos.append((id_usuario, id_exemplar, id_livro, momento_emprestimo, data_devolucao))

    # Inserir dados fictícios na tabela Emprestimo
    cursor.executemany('''INSERT OR IGNORE INTO Emprestimo (idUsuário, idExemplar, idLivro, Timestamp_do_Momento_do_Emprestimo, Data_de_Devolução_do_Exemplar)
                        VALUES (?, ?, ?, ?, ?)''', emprestimos)

    # Salva as alterações e fecha a conexão
    conn.commit()
    conn.close()

# Função para consultar a tabelas do BD e chekar inserção
def consultar_tabela_livro(banco_dados):
    # Conexão com o banco de dados
    conn = sqlite3.connect(banco_dados)
    cursor = conn.cursor()

    # Consulta a tabela
    #cursor.execute("SELECT * FROM Autor")
    #cursor.execute("SELECT * FROM Editora")
    cursor.execute("SELECT * FROM País")
    #cursor.execute("SELECT * FROM Cidade")
    #cursor.execute("SELECT * FROM Tipo_de_Gênero_Literário")
    #cursor.execute("SELECT * FROM Tipo_de_Gênero")
    #cursor.execute("SELECT * FROM Tipo_de_Escolaridade")
    #cursor.execute("SELECT * FROM Tipo_de_Estado_Cívil")

    tabelaSelecionada = cursor.fetchall()

    # Mostra os resultados
    #print("Livros:")
    for tabela in tabelaSelecionada:
        print(tabela)

    # Fecha a conexão
    conn.close()

# Arquivo SQL e banco de dados
arquivo_sql = "/workspaces/Python_Projects_Portfolio/BibliotecaIGTI/SQLgenerateFromModelagem.sql"
banco_dados = "bibliotecaIGTI.db"

# Executa o arquivo SQL
executar_sql(arquivo_sql, banco_dados)

# Inserir Dados Ficticios
insert_data_sql(banco_dados)

# Consulta a tabela Livro
consultar_tabela_livro(banco_dados)