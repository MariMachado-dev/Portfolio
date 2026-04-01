const filmesPorData = {
    "28": [
        {
            nome: "Wicked",
            poster: "Imagens/wicked-poster.jpeg",
            horarios: ["13:00","15:30","18:00","20:30"],
            filmeId: 17,
            sinopse: "Em uma terra mágica, Elphaba, uma jovem com pele verde, descobre seus poderes. Ela faz amizade com Glinda, uma garota popular, mas suas diferenças as afastam. Juntas, elas enfrentam desafios e revelam segredos que mudam o destino de Oz. Uma história de amizade, coragem e aceitação."
        },
        {
            nome: "Avatar",
            poster: "Imagens/poster5.jpeg",
            horarios: ["14:00","16:30","19:00","21:30"],
            filmeId: 19,
            sinopse: "Em um futuro distante, Jake Sully, um ex-fuzileiro paraplégico, é enviado ao planeta Pandora. Lá, ele se conecta com os Na'vi através de um avatar e se envolve em um conflito entre humanos e nativos. Conforme Jake se aproxima dos Na'vi, ele questiona sua lealdade e luta para proteger Pandora. Uma aventura épica de descoberta e redenção."
        },
        {
            nome: "Superman",
            poster: "Imagens/poster4.jpg",
            horarios: ["12:30","15:00","17:30","20:00"],
            filmeId: 2,
            sinopse: "Clark Kent, um jovem jornalista com habilidades sobre-humanas, descobre suas origens alienígenas. Adotado por uma família humana, ele luta para equilibrar sua vida dupla como Superman, protegendo a Terra de ameaças enquanto mantém sua identidade secreta. Uma história de heroísmo e responsabilidade."
        }
    ],
    "29": [
        {
            nome: "Toy Story 4",
            poster: "Imagens/foto3_filme.avif",
            horarios: ["14:00","16:30","19:00","21:30"],
            filmeId: 18,
            sinopse: "Em um mundo onde brinquedos ganham vida, Woody e Buzz Lightyear embarcam em uma nova aventura com novos amigos. Quando Bonnie cria um novo brinquedo chamado Forky, Woody assume a responsabilidade de protegê-lo. Juntos, eles enfrentam desafios e descobrem o verdadeiro significado da amizade e do pertencimento."
        },
        {
            nome: "Saw - Jogos Mortais",
            poster: "Imagens/poster_saw.jpg",
            horarios: ["13:00","15:30","18:00","20:30"],
            filmeId: 15,
            sinopse: "Jigsaw. Um homem que acredita que a vida é um presente e que as pessoas não valorizam isso. Ele cria jogos mortais para testar a vontade de viver de suas vítimas, forçando-as a fazer escolhas extremas para sobreviver. Um thriller psicológico cheio de suspense e reviravoltas. Aviso: contém cenas fortes. Indicado para maiores de 18 anos."
        },
        {
            nome: "O Poderoso Chefão",
            poster: "Imagens/poster_PoderosoChefao.webp",
            horarios: ["12:30","15:00","17:30","20:00"],
            filmeId: 11,
            sinopse: "Na década de 1940, a família Corleone, liderada por Vito Corleone, é uma das mais poderosas da máfia em Nova York. Quando Vito é alvo de um atentado, seu filho Michael, inicialmente relutante, assume o controle da família. A história acompanha a ascensão de Michael ao poder, enfrentando traições e desafios para proteger seu legado. Um clássico do cinema sobre poder, lealdade e corrupção."
        }
    ],
    "30": [
        {
            nome: "Vingadores: Ultimato",
            poster: "Imagens/poster6.jpeg",
            horarios: ["12:00","14:00","17:00", "20:00", "22:30"],
            filmeId: 1,
            sinopse: "Após os eventos devastadores de 'Vingadores: Guerra Infinita', os heróis sobreviventes enfrentam a perda e a desolação. Com a ajuda de aliados inesperados, eles elaboram um plano para reverter as ações de Thanos e restaurar o equilíbrio no universo. Uma épica conclusão para a saga dos Vingadores, repleta de ação, emoção e sacrifício. O final imperdível do Universo Cinematográfico Marvel."
        },
        {
            nome: "A Grande Viagem da Sua Vida",
            poster: "Imagens/poster2.jpeg",
            horarios: ["15:00","18:00"],
            filmeId: 5,
            sinopse: "Três amigos de infância embarcam em uma viagem de carro pelo país para cumprir o último desejo de um deles, que está gravemente doente. Ao longo do caminho, eles enfrentam desafios, redescobrem a amizade e aprendem a valorizar cada momento juntos. Uma comédia dramática sobre a importância da amizade e da vida."
        },
         {
            nome: "Mad Max: Estrada da Fúria",
            poster: "Imagens/postermadmax.jpg",
            horarios: ["13:30","19:30"],
            filmeId: 3,
            sinopse: "Em um futuro pós-apocalíptico, Max Rockatansky, um ex-policial solitário, se une a Furiosa, uma guerreira rebelde, para escapar de um tirano que controla os recursos restantes. Juntos, eles enfrentam perigos mortais em uma perseguição implacável através do deserto. Uma ação intensa e visualmente deslumbrante sobre sobrevivência e redenção"
        }
    ]
};

const selectData = document.getElementById("selectData");
const container = document.getElementById("filmes-container");

function mostrarFilmes(dia) {
    container.innerHTML = ""; // limpa o container
    const filmes = filmesPorData[dia] || [];
    filmes.forEach(filme => {
        const filmeWrapper = document.createElement("div");
        filmeWrapper.classList.add("filme-wrapper");
        filmeWrapper.innerHTML = `
            <div class="img-container">
                <img src="${filme.poster}" alt="Poster do filme">
                <div id="txt_img_principal">${filme.nome}</div>
            </div>
            <div class="horarios-container">
                <div id="container_card">
                    ${filme.horarios.map(h => `<a class="opcoes_genero" href="compra.html?filmeId=${filme.filmeId}">${h}</a>`).join("")}
                </div>
                <div class="sinopse">
                    <p>${filme.sinopse}</p>
                </div>
            </div>
        `;
        container.appendChild(filmeWrapper);
    });
}

// Carrega os filmes do dia inicial
mostrarFilmes(selectData.value);

// Atualiza os filmes ao mudar o select
selectData.addEventListener("change", () => {
    mostrarFilmes(selectData.value);
});
