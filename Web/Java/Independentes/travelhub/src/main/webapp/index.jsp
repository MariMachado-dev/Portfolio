<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<%@ page import="java.util.List" %>
<%@ page import="dto.EntretenimentoDTO" %>

<!DOCTYPE html>
<html lang="pt-BR">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>TravelHub</title>
    <link rel="stylesheet" href="css/style.css">
</head>

<body>
    <header class="header">
        <div class="container header-content">
            <a href="index.jsp" class="logo">
                Travel<span>Hub</span>
            </a>
            <nav class="nav">
                <a href="#inicio">Início</a>
                <a href="entretenimento.jsp">Entretenimento</a>
                <a href="#cambio">Câmbio</a>
                <a href="#sobre">Sobre</a>
            </nav>
        </div>
    </header>

    <main id="inicio">
        <section class="hero">
            <div class="container hero-content">
                <div class="hero-text">
                    <p class="tag">SEU ASSISTENTE DE VIAGEM</p>
                    <h1>
                        Planeje sua viagem
                        <span>em um só lugar.</span>
                    </h1>

                    <p class="hero-description">
                        Encontre opções de entretenimento e consulte
                        cotações de moedas para facilitar o planejamento
                        da sua viagem.
                    </p>
                </div>


                <div class="search-card">
                    <h2>Para onde você vai?</h2>
                    <p>
                        Pesquise uma cidade para encontrar informações
                        básicas sobre o destino.
                    </p>
                     <!-- Lógica de exibicao de erro Caso cidade = não encontrada -->
                    <%
                        List<EntretenimentoDTO> entretenimentos = (List<EntretenimentoDTO>) request.getAttribute("entretenimentos");
                        Boolean encontrouEntretenimento = (Boolean) request.getAttribute("encontrouEntretenimento");
                    %>

                    <%if (Boolean.FALSE.equals(encontrouEntretenimento)) {%>
                    <p class="city-error">Nenhum lugar de entretenimento encontrado.</p>
                    <%}%>

                    <form action="index" method="get" class="search-form">
                        <div class="input-group">
                            <label for="cidade">Cidade</label>
                            <input type="text" id="cidade" name="cidade" placeholder="Ex.: Rio de Janeiro">
                        </div>
                        <button type="submit">Pesquisar</button>
                    </form>
                </div>
            </div>
        </section>

        <section class="section" id="entretenimento">
            <div class="container">
                <div class="section-title">
                    <p class="tag">ENTRETENIMENTO</p>
                    <h2>Descubra o que fazer no seu destino.</h2>
                    <p>
                        Encontre opções de entretenimento na cidade
                        pesquisada.
                    </p>
                </div>

                <div class="cards">
                    <div class="category-card">
                        <div class="icon">🎭</div>
                        <h3>Teatros</h3>
                        <p>Encontre teatros e apresentações.</p>
                    </div>

                    <div class="category-card">
                        <div class="icon">🎬</div>
                        <h3>Cinemas</h3>
                        <p>Descubra cinemas e opções de filmes.</p>
                    </div>

                    <div class="category-card">
                        <div class="icon">🏛️</div>
                        <h3>Museus</h3>
                        <p>Conheça museus e atrações culturais.</p>
                    </div>

                    <div class="category-card">
                        <div class="icon">🎵</div>
                        <h3>Eventos</h3>
                        <p>Veja eventos e atividades disponíveis.</p>
                    </div>
                </div>
                
                <!-- RESULTADO DA PESQUISA -->
                <% if (Boolean.TRUE.equals(encontrouEntretenimento)) { %>
                <div class="city-found"> 
                    <h3>Cidade encontrada!</h3> 
                    <p>Deseja ir para a página de entretenimento?</p> 
                    <div class="city-found-buttons"> 
                        <a href="entretenimento?cidade=<%= request.getAttribute("cidade") %>" class="city-button primary">Sim</a>
                        <button type="button" class="city-button secondary" onclick="this.closest('.city-found').style.display='none'">Não</button>
                    </div> 
                </div>

                <%
                    }
                %>
            </div>
        </section>

        <section class="exchange-section" id="cambio">
            <div class="container exchange-content">
                <div class="exchange-text">
                    <p class="tag">CÂMBIO</p>
                    <h2>Consulte a cotação das moedas.</h2>
                    <p>
                        Assim como com a seção de entretenimento, a página inicial apresenta apenas um exemplo
                        de conversão entre o Real e o Dólar.
                        Para realizar conversões entre outras moedas
                        e consultar mais informações, acesse a página
                        completa de Câmbio.
                    </p>

                    <a href="cambio.jsp" class="secondary-button">
                        Acessar página de Câmbio
                    </a>
                </div>

                <div class="exchange-card">
                    <div class="input-group">
                        <label for="valor">Exemplo</label>
                        <input type="number"id="valor"value="100"readonly>
                    </div>

                    <div class="currency-row">
                        <div class="input-group">
                            <label for="origem">De</label>
                            <select id="origem" disabled>
                                <label value="BRL">BRL - Real</label>
                            </select>
                        </div>
                        <div class="arrow"> → </div>
                        <div class="input-group">
                            <label for="destino">Para</label>
                            <select id="destino" disabled>
                                <label value="USD">USD - Dólar</label>
                            </select>
                        </div>
                    </div>

                    <div class="conversion-result">
                        <span>Exemplo de resultado</span>
                        <strong>R$ 100,00 → US$ --,--</strong>
                        <small>Cotação fornecida pela API.</small>
                    </div>

                    <a href="cambio.jsp" class="exchange-button">
                        Fazer uma conversão
                    </a>
                </div>
            </div>
        </section>

                <section class="about-section" id="sobre">
            <div class="container">
                <div class="about-content">
                    <div class="about-text">
                        <p class="tag">SOBRE O TRAVELHUB</p>
                        <h2>Uma aplicação para facilitar o planejamento de viagens.</h2>
                        <p>
                            O TravelHub é uma aplicação web desenvolvida
                            para reunir diferentes informações relacionadas
                            ao planejamento de uma viagem.
                        </p>

                        <p>
                            O projeto combina recursos de consulta de
                            entretenimento e conversão de moedas, utilizando
                            uma API externa para fornecer informações
                            atualizadas ao usuário.
                        </p>
                    </div>

                    <div class="about-features">
                        <div class="about-feature">
                            <span></span>
                            <div>
                                <h3>Destino</h3>
                                <p>Pesquise uma cidade para iniciar seu planejamento.</p>
                            </div>
                        </div>

                        <div class="about-feature">
                            <span></span>
                            <div>
                                <h3>Entretenimento</h3>
                                <p>Encontre locais e atividades disponíveis no destino.</p>
                            </div>
                        </div>

                        <div class="about-feature">
                            <span></span>
                            <div>
                                <h3>Câmbio</h3>
                                <p>Consulte a conversão entre diferentes moedas.</p>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </section>
    </main>

    <footer class="footer">
        <div class="container footer-content">
            <div class="footer-brand">
                <div class="logo">
                    Travel<span>Hub</span>
                </div>
                <p>Seu assistente para planejar viagens.</p>
            </div>

            <div class="footer-links">
                <h3>TravelHub</h3>
                <a href="#inicio">Início</a>
                <a href="#sobre">Sobre</a>
                <a href="entretenimento.jsp">Entretenimento</a>
                <a href="#cambio">Câmbio</a>
            </div>


            <div class="footer-info">
                <h3>Projeto acadêmico</h3>
                <p>
                    Aplicação web desenvolvida em Java,
                    utilizando Maven, banco de dados,
                    API e padrões de projeto.
                </p>
            </div>
        </div>


        <div class="footer-bottom">
            <p>
                © 2026 TravelHub — Projeto acadêmico.
            </p>
        </div>
    </footer>
</body>
</html>