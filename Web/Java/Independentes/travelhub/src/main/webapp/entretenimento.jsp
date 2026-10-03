<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<!DOCTYPE html>
<html lang="pt-BR">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Entretenimento | TravelHub</title>
    <link rel="stylesheet" href="css/style.css">
</head>

<body>
    <header class="header">
        <div class="container header-content">
            <a href="index.jsp" class="logo">
                Travel<span>Hub</span>
            </a>
            <nav class="nav">
                <a href="index.jsp">Início</a>
                <a href="entretenimento.jsp">Entretenimento</a>
                <a href="cambio.jsp">Câmbio</a>
                <a href="index.jsp#sobre">Sobre</a>
            </nav>
        </div>
    </header>

    <main>
        <section class="entertainment-hero">
            <div class="container">
                <p class="tag">ENTRETENIMENTO</p>
                <h1>Encontre o que fazer<span>no seu destino.</span></h1>

                <p class="entertainment-intro">
                    Pesquise uma cidade e encontre opções de
                    entretenimento, cultura e atividades para
                    aproveitar durante sua viagem.
                </p>

                <form action="entretenimento" method="get" class="entertainment-search">
                    <div class="input-group">
                        <label for="cidade">Cidade</label>
                        <input type="text" id="cidade" name="cidade" placeholder="Ex.: Rio de Janeiro">
                    </div>

                    <button type="submit">Pesquisar</button>
                </form>
            </div>
        </section>

        <section class="entertainment-results">
            <div class="container">
                <div class="results-header">
                    <div>
                        <p class="tag">RESULTADOS</p>
                        <h2>Opções encontradas</h2>
                        <p>Resultados disponíveis para a cidade pesquisada.</p>
                    </div>

                    <div class="results-filter">
                        <label for="filtro">Filtrar por</label>
                        <select id="filtro">
                            <option>Todas as categorias</option>
                            <option>Teatros</option>
                            <option>Cinemas</option>
                            <option>Museus</option>
                            <option>Eventos</option>
                        </select>
                    </div>
                </div>

                <div class="entertainment-result-list">
                    <%
                        if (entretenimentos != null) {
                            for (EntretenimentoDTO entretenimento : entretenimentos) {
                    %>

                    <div class="entertainment-result">
                        <div class="result-icon"><%= entretenimento.getIcone() %></div>
                        <div class="result-info">
                            <span class="result-type"> <%= entretenimento.getCategoria() %></span>
                            <h3> <%= entretenimento.getNome() %></h3>
                            <p> <%= entretenimento.getDescricao() %></p>
                            <span class="result-location"><%= request.getAttribute("cidade") %></span>
                        </div>

                        <button type="button" class="result-button">Ver detalhes</button>
                    </div>
                    <%
                            }
                        }
                    %>

                <div class="results-placeholder">
 
                    <p> 
                        Mais resultados serão carregados 
                        conforme a cidade e os filtros selecionados. 
                    </p> 
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
                <a href="index.jsp">Início</a>
                <a href="#sobre">Sobre</a>
                <a href="#entretenimento">Entretenimento</a>
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