document.addEventListener('DOMContentLoaded', function() {
    // Recupera o nome do filme
    const nomeFilme = localStorage.getItem('filmeSelecionado');
    if (nomeFilme && document.getElementById('filme')) {
        document.getElementById('filme').value = nomeFilme;
    }

    // Recupera o valor total
    const total = localStorage.getItem('totalIngressos');
    if (total && document.getElementById('valorTotal')) {
        document.getElementById('valorTotal').textContent = total;
    } else if(document.getElementById('valorTotal')) {
        document.getElementById('valorTotal').textContent = '0.00';
    }

    // Alerta do botão de pagamento
    const button = document.getElementById('pagamento');
    const alerta = document.getElementById('alerta');
    if (button && alerta) {
        button.addEventListener('click', function(event) {
            event.preventDefault();
            alerta.style.display = 'block';
            setTimeout(() => {
                alerta.style.display = 'none';
                window.location.href = "index.html";
            }, 3000);
        });
    }
});