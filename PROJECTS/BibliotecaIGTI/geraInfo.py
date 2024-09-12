import sqlite3
import pandas as pd

# Quantidade de Livros que cada autor possui
def qtd_livro_autor(banco_dados):
    # Conexão com o banco de dados
    conn = sqlite3.connect(banco_dados)
    cursor = conn.cursor()

    cursor.execute("SELECT aut.Código_do_Autor, aut.Nome_Completo_do_Autor,count(*) as qtd_livro_autor FROM Livro liv left join Autor aut on liv.idAutor = aut.Código_do_Autor group by aut.Código_do_Autor, aut.Nome_Completo_do_Autor")

    tabelaSelecionada = cursor.fetchall()

    # Obter os nomes das colunas
    columns = [description[0] for description in cursor.description]

    # Criar o DataFrame
    df = pd.DataFrame(tabelaSelecionada, columns=columns)
    print(df)

    # Fecha a conexão
    conn.close()

# Usuários que começam com a letra T
def usuario_por_letra(banco_dados):
    # Conexão com o banco de dados
    conn = sqlite3.connect(banco_dados)
    cursor = conn.cursor()

    cursor.execute("SELECT * FROM Usuário WHERE Nome_do_Usuário LIKE ?", ('T%',))

    tabelaSelecionada = cursor.fetchall()

    # Obter os nomes das colunas
    columns = [description[0] for description in cursor.description]

    # Criar o DataFrame
    df = pd.DataFrame(tabelaSelecionada, columns=columns)
    print(df)

    # Fecha a conexão
    conn.close()

# Usuários suspensos por não devolverem livros alugados
def usuario_suspenso(banco_dados):
    # Conexão com o banco de dados
    conn = sqlite3.connect(banco_dados)
    cursor = conn.cursor()

    cursor.execute("SELECT * FROM Usuário WHERE Indicador_de_Usuário_Ativo = 0")

    tabelaSelecionada = cursor.fetchall()

    # Obter os nomes das colunas
    columns = [description[0] for description in cursor.description]

    # Criar o DataFrame
    df = pd.DataFrame(tabelaSelecionada, columns=columns)
    print(df)

    # Fecha a conexão
    conn.close()

    # Consulta a tabela
    #cursor.execute("SELECT * FROM Autor")
    #cursor.execute("SELECT * FROM Editora")
    #cursor.execute("SELECT * FROM Livro")
    #cursor.execute("SELECT * FROM País")
    #cursor.execute("SELECT * FROM Usuário")
    #cursor.execute("SELECT * FROM Cidade")
    #cursor.execute("SELECT * FROM Emprestimo")
    #cursor.execute("SELECT * FROM Tipo_de_Gênero_Literário")
    #cursor.execute("SELECT * FROM Tipo_de_Gênero")
    #cursor.execute("SELECT * FROM Tipo_de_Escolaridade")
    #cursor.execute("SELECT * FROM Tipo_de_Estado_Cívil")

# banco de dados
banco_dados = "bibliotecaIGTI.db"

# Executa - Quantidade de Livros que cada autor possui
#qtd_livro_autor(banco_dados)

# Executa - Usuários que começam com a letra T
#usuario_por_letra(banco_dados)

# Executa - Usuários suspensos por não devolverem livros alugados
#usuario_suspenso(banco_dados)s