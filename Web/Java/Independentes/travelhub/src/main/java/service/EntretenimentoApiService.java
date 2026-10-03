package service;

import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.util.ArrayList;
import java.util.List;

import com.fasterxml.jackson.databind.ObjectMapper;

import dto.EntretenimentoDTO;
import dto.FeatureEntretenimentoDTO;
import dto.LocalizacaoDTO;
import dto.PropriedadesEntretenimentoDTO;
import dto.RespostaEntretenimentoDTO;

public class EntretenimentoApiService {
    private LocalizacaoApiService localizacaoApiService;

    public EntretenimentoApiService() {
        localizacaoApiService = new LocalizacaoApiService();
    }

    public List<EntretenimentoDTO> buscarEntretenimento(String cidade) {
        LocalizacaoDTO localizacao = localizacaoApiService.buscaLocalizacao(cidade);

        if (localizacao == null) {
            return new ArrayList<>();
        }

        double latitude = localizacao.getLatitude();
        double longitude = localizacao.getLongitude();

        //Requisicao de info de cidade (Geoapify)
        String url = 
                      "https://api.geoapify.com/v2/places"
                    + "?categories=entertainment"
                    + "&filter=circle:" + longitude + "," + latitude + ",5000"
                    + "&limit=20"
                    + "&apiKey=312d5ca6bff547afa751b18f2fba8682";

        HttpRequest request = HttpRequest.newBuilder().uri(URI.create(url)).GET().build();
        HttpClient client = HttpClient.newHttpClient();

        try {
            HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());
            String json = response.body();

            ObjectMapper mapper = new ObjectMapper();
            RespostaEntretenimentoDTO resposta = mapper.readValue(json, RespostaEntretenimentoDTO.class);

            //Percorre resultados do Geopify
            List<EntretenimentoDTO> entretenimentos = new ArrayList<>();

            for (FeatureEntretenimentoDTO feature : resposta.getFeatures()) {
                PropriedadesEntretenimentoDTO propriedades = feature.getProperties();

                EntretenimentoDTO entretenimento = new EntretenimentoDTO();
                entretenimento.setNome(propriedades.getName());
                entretenimento.setDescricao(propriedades.getFormatted());
                entretenimento.setCategoria(propriedades.getCategories());
                entretenimento.setIcone(definirIcone(propriedades.getCategories()));

                entretenimentos.add(entretenimento);

                return entretenimentos;
            }
        }

        catch(Exception e) {
            e.printStackTrace();
            return new ArrayList<>();
        }

        return null;
    }

    private String definirIcone(String categoria) {
        if (categoria == null) {
            return "❓";
        }

        categoria = categoria.toLowerCase();

        if (categoria.contains("museum")) {
            return "🏛️";
        }

        if (categoria.contains("theatre")) {
            return "🎭";
        }

        if (categoria.contains("cinema")) {
            return "🎬";
        }

        if (categoria.contains("aquarium")) {
            return "🐠";
        }

        if (categoria.contains("event")) {
            return "🎵";
        }

        return "❓";
    }
}
