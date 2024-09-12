select 	
ROW_NUMBER() OVER(ORDER BY itemcode ASC) AS 'Row#', -- Numera as linhas da consulta
ROW_NUMBER() OVER(PARTITION BY linenum ORDER BY linenum ASC) AS 'Row*' , -- organiza as linhas de acordo com um terceiro fator
linenum,
nullif(TOTALSUMSY, OPENSUMSYS) AS 'Null If',			-- Converte os valores identicos das 2 colunas em Nulo
coalesce(itemcode,dscription) AS 'Coalesce',			-- Verfica 2 ou mais colunas e apresenta o primeiro nao nulo
lower(dscription) AS 'Lower',							-- Converte as letras Maiusculas em minusculas      
upper(dscription) AS 'Upper',							-- Converte as minunsculas em maiusculas
len(ITEMCODE) as 'Len',									-- Mostra a quantidade de caracteres contidos em um campo
replace(ItemCode,'A','CR7') as 'Replace',				-- Troca apenas uma palavra especifica desejada por outra
round(TOTALSUMSY,0) as 'Round',							-- Arredonda o campo escolhido de acordo com a quantidade de casas decimais
TOTALSUMSY%2 as 'Mod',									-- Resto da divisão
ShipDate + 30 as 'Mudando a data',						-- Aumenta o numero de dias na data oficial
convert(CHAR,ShipDate,103) as 'dd mm aa',				-- Mudando dada para Dia/Mês/Ano padrão Brasil
SUBSTRING(CAST(ItemCode AS VARCHAR),1,1) AS 'SUBSTRING'	-- Usado para escolher quantos caracteres serão mostrados e quais deles

from RDR1

where 
nullif(TOTALSUMSY, OPENSUMSYS) is not null
and docentry not in(select DocEntry from ORDR where DocEntry = '127')




