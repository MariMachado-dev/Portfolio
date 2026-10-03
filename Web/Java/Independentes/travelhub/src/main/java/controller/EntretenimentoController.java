package controller;

import java.io.IOException;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import dto.EntretenimentoDTO;
import service.TravelHubService;

@WebServlet("/entretenimento")
public class EntretenimentoController extends HttpServlet {
    private TravelHubService travelHubService;

    @Override 
    public void init() throws ServletException {
        travelHubService = new TravelHubService();
    }

    @Override 
    protected void doGet(HttpServletRequest request,
                        HttpServletResponse response) throws ServletException, IOException {
        
        String cidade = request.getParameter("cidade");
        request.setAttribute("cidade", cidade);
        List<EntretenimentoDTO> entretenimentos = travelHubService.buscarEntretenimento(cidade);
        request.setAttribute("entretenimentos", entretenimentos);
        request.getRequestDispatcher("/entretenimento.jsp").forward(request, response);
    }
}
