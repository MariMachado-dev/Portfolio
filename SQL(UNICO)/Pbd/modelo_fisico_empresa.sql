CREATE TABLE DEPARTAMENTOS (
    id INT PRIMARY KEY,
    nome_departamento VARCHAR(100) NOT NULL
);

CREATE TABLE FUNCIONARIOS (
    id INT PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    salario DECIMAL(10,2) NOT NULL,
    departamento_id INT,
    FOREIGN KEY (departamento_id)
        REFERENCES DEPARTAMENTOS(id)
);

CREATE TABLE PROJETOS (
    id INT PRIMARY KEY,
    nome_projeto VARCHAR(100) NOT NULL,
    orcamento DECIMAL(10,2) NOT NULL,
    departamento_id INT,
    FOREIGN KEY (departamento_id)
        REFERENCES DEPARTAMENTOS(id)
);