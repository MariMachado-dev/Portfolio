package service;

import java.net.URI;
import java.net.URLEncoder;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.nio.charset.StandardCharsets;

import com.fasterxml.jackson.databind.ObjectMapper;

import dto.LocalizacaoDTO;
import dto.RespostaLocalizacaoDTO;

public class LocalizacaoApiService {
    public LocalizacaoDTO buscaLocalizacao(String cidade) {
        String cidadeCodificada = URLEncoder.encode(cidade, StandardCharsets.UTF_8);

        HttpRequest request = HttpRequest.newBuilder()
                .uri(URI.create(
                    "https://geocoding-api.open-meteo.com/v1/search"
                    + "?name=" + cidadeCodificada
                    + "&count=1"
                    + "&language=pt"
                    + "&format=json"
                ))
                .GET()
                .build();

            HttpClient client = HttpClient.newHttpClient();

        try {
            HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());
            String json = response.body();

            ObjectMapper mapper = new ObjectMapper();
            RespostaLocalizacaoDTO resposta = mapper.readValue(json, RespostaLocalizacaoDTO.class);

            if (resposta.getResults() == null || resposta.getResults().isEmpty()) {
                    System.out.println("Nenhuma localização encontrada!");
                return null;
            }

            return resposta.getResults().get(0);
        }

        catch (Exception e) {
            e.printStackTrace();
            return null;
        }
        
    }
}

