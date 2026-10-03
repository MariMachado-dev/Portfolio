package com.biblioteca.service;

import java.util.ArrayList;
import java.util.List;

import org.springframework.stereotype.Service;

import com.biblioteca.exception.LivroNaoEncontradoException;
import com.biblioteca.model.Livro;

@Service
public class LivroService {
    List<Livro> livros = new ArrayList<>();
        
    public LivroService() {     
        livros.add(new Livro(1, "O Hobbit", "J. R. R. Tolkien"));
        livros.add(new Livro(2, "1984", "George Orwell"));
        livros.add(new Livro(3, "Dom Casmurro", "Machado de Assis"));
    }

    public List<Livro> buscarLivro() {
        return livros;
    }

    public Livro buscarLivroPorId(int id) {
        List<Livro> livros = buscarLivro();

        for (Livro livro : livros) {
            if (livro.getId() == id) {
                return livro;
            }
        }

        throw new LivroNaoEncontradoException("Livro com ID " + id + " não encontrado.");
    }

    public Livro buscarLivroPorTitulo(String titulo) {
        List<Livro> livros = buscarLivro();

        for (Livro livro : livros) {
            if (livro.getTitulo().equals(titulo)) {
                return livro;
            }
        }

        throw new LivroNaoEncontradoException("Livro com título " + titulo + " não encontrado.");
    }

    public Livro adicionarLivro(Livro livro) {
        livros.add(livro);
        return livro;
    }

    public void removerLivro(int id) {
        Livro livro = buscarLivroPorId(id);
        livros.remove(livro);
    }

    public Livro atualizarLivro(int id, Livro livroAtualizado) {
        Livro livroExistente = buscarLivroPorId(id);

        livroExistente.setTitulo(livroAtualizado.getTitulo());
        livroExistente.setAutor(livroAtualizado.getAutor());
        
        return livroExistente;
    }
}