package dto;

import java.util.List;

import com.fasterxml.jackson.annotation.JsonIgnoreProperties;

@JsonIgnoreProperties(ignoreUnknown=true)
public class RespostaEntretenimentoDTO {
    private List<FeatureEntretenimentoDTO> features;

    public List<FeatureEntretenimentoDTO> getFeatures() {
        return features;
    }

    public void setFeatures(List<FeatureEntretenimentoDTO> features) {
        this.features = features;
    }
}
