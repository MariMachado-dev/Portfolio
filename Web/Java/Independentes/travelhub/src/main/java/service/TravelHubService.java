package service;

import java.util.List;

import dto.EntretenimentoDTO;

public class TravelHubService {
    private EntretenimentoApiService entretenimentoApiService;


    //Regras do EntretenimentoAPI
    public TravelHubService() {
        entretenimentoApiService = new EntretenimentoApiService();
    }

     public List<EntretenimentoDTO> buscarEntretenimento(String cidade) {
        return entretenimentoApiService.buscarEntretenimento(cidade);
    }
}
