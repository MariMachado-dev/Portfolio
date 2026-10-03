package dto;

import com.fasterxml.jackson.annotation.JsonIgnoreProperties;

@JsonIgnoreProperties(ignoreUnknown = true)
public class FeatureEntretenimentoDTO {

    private PropriedadesEntretenimentoDTO properties;

    public PropriedadesEntretenimentoDTO getProperties() {
        return properties;
    }

    public void setProperties(PropriedadesEntretenimentoDTO properties) {
        this.properties = properties;
    }
}