create table Paciente (
    id_Paciente int primary key auto_increment,
    nome varchar(100) not null,
    cpf varchar(11) not null unique,
    sexo char(1) not null,
    telefone varchar(15),
    dataNascimento date not null,
    plano_saude varchar(50)
);

create table Medico (
    id_Medico int primary key auto_increment,
    nome varchar(100) not null,
    crm varchar(11) not null unique, /*doc profissional de registro de medico*/
    telefone varchar(15),
    email varchar(100),
    especialidade varchar(50) not null
);

create table Prontuario (
    id_Prontuario int primary key auto_increment,
    id_Paciente int not null,
    historico_paciente varchar(255),
    historico_familiar varchar(255),
    medicamentos_atuais varchar(255),
    data_atualizacao date,
    risco_paciente int,
    foreign key (id_Paciente) references Paciente(id_Paciente)
);

create table Consulta (
    id_Consulta int primary key auto_increment,
    id_Paciente int not null,
    id_Medico int not null,
    id_Prontuario int not null,
    data_consulta date not null,
    diagnostico varchar(255) not null,
    sintomas varchar(255),
    status_consulta varchar(20) not null,
    foreign key (id_Paciente) references Paciente(id_Paciente),
    foreign key (id_Medico) references Medico(id_Medico),
    foreign key (id_Prontuario) references Prontuario(id_Prontuario)
); 


create table Exame (
    id_Exame int primary key auto_increment,
    id_Paciente int not null,
    id_Medico int not null,
    id_Consulta int not null,
    id_Prontuario int not null,
    data_solicitacao date not null,
    data_resultado date,
    tipo varchar(50) not null,
    resultado varchar(255) not null,
    status_exame varchar(20) not null,
    foreign key (id_Consulta) references Consulta(id_Consulta),
    foreign key (id_Paciente) references Paciente(id_Paciente),
    foreign key (id_Medico) references Medico(id_Medico),
    foreign key (id_Prontuario) references Prontuario(id_Prontuario)
);