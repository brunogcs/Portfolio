# Data Ecosystem Simulation

## Descrição do Projeto
O projeto **"Data Ecosystem Simulation"** tem como objetivo criar uma simulação de um ecossistema de dados que abrange a coleta, processamento, armazenamento e análise de dados. Ele será desenvolvido utilizando Python e/ou Scala, com integração ao Microsoft Azure e ferramentas de orquestração como Apache Airflow. O projeto também incluirá práticas de DevOps e CI/CD para garantir a eficiência e a qualidade do código.

Dados abertos obtidos por: https://dadosabertos.bcb.gov.br/dataset/dolar-americano-usd-todos-os-boletins-diarios

## Estrutura do Repositório
data-ecosystem-simulation/
│
├── data_ingestion/
│   ├── ingest_data.py
│   └── requirements.txt
│
├── data_processing/
│   ├── process_data.py
│   └── requirements.txt
│
├── data_storage/
│   ├── create_storage.py
│   └── requirements.txt
│
├── data_quality/
│   ├── data_quality_checks.py
│   └── requirements.txt
│
├── airflow/
│   ├── dags/
│   │   └── data_pipeline.py
│   └── requirements.txt
│
├── README.md
└── .gitignore


## Componentes do Projeto

### Data Ingestion
- Um script em Python/Scala para coletar dados de diferentes fontes (APIs, bancos de dados, arquivos CSV).
- Implementação de políticas de governança de dados para garantir a qualidade e a consistência.

### Data Processing
- Um script que processa os dados ingeridos, aplicando transformações necessárias (limpeza, agregação, etc.).
- Utilização de plataformas de processamento de dados como Databricks ou Azure Data Factory.

### Data Storage
- Criação de um ambiente de armazenamento de dados utilizando Azure Blob Storage ou Azure Data Lake.
- Implementação de diferentes formatos de dados (parquet, JSON, etc.) para otimização de armazenamento e consulta.

### Data Quality
- Implementação de verificações de qualidade de dados para garantir a integridade e a segurança dos dados.
- Desenvolvimento de soluções de Data Quality e Data Governance.

### Orquestração com Airflow
- Criação de um DAG (Directed Acyclic Graph) no Apache Airflow para orquestrar o fluxo de dados entre as etapas de ingestão, processamento e armazenamento.
- Configuração de tarefas para monitorar e gerenciar o pipeline de dados.

### Documentação
- Um README.md detalhando o projeto, como configurá-lo e executá-lo, além de explicar as decisões arquitetônicas tomadas.
- Instruções sobre como contribuir para o projeto e melhores práticas de desenvolvimento.

## Tecnologias Utilizadas
- **Linguagens:** Python e/ou Scala
- **Plataformas:** Microsoft Azure, Databricks, Apache Airflow
- **Formatos de Dados:** Parquet, JSON
- **DevOps:** CI/CD com GitHub Actions

## Como Contribuir
- Criar issues para melhorias ou bugs encontrados.
- Submeter pull requests com novas funcionalidades ou correções.
- Participar de discussões sobre a arquitetura e as melhores práticas.

## Conclusão
Este projeto não apenas demonstra suas habilidades técnicas em Arquitetura de Dados, mas também reflete os valores e a cultura da XP Inc., como foco no cliente, sonho grande e espírito empreendedor. Ao compartilhar este projeto no GitHub, você poderá mostrar sua capacidade de trabalhar em equipe, sua adaptabilidade e seu comprometimento com a qualidade e a inovação.
