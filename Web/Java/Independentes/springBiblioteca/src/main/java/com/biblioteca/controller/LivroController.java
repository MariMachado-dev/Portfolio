package com.biblioteca.controller;

import java.util.List;

import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

import com.biblioteca.model.Livro;
import com.biblioteca.service.LivroService;

@RestController
public class LivroController {
    private final LivroService livroService;

    public LivroController(LivroService livroService) {
        this.livroService = livroService;
    }

    @GetMapping("/livros")
    public List<Livro> livros() {
        return livroService.buscarLivro();
    }

    @GetMapping("/livros/{id}")
    public Livro buscarLivro(@PathVariable int id) {
        return livroService.buscarLivroPorId(id);
    }

    @GetMapping("/livros/titulo/{titulo}")
    public Livro buscarLivro(@PathVariable String titulo) {
        return livroService.buscarLivroPorTitulo(titulo);
    }

    @PostMapping("/livros")
    public ResponseEntity<Livro> adicionarLivro(@RequestBody Livro livro) {
        Livro novoLivro = livroService.adicionarLivro(livro);
        return ResponseEntity.status(HttpStatus.CREATED).body(novoLivro);
    }

    @DeleteMapping("/livros/{id}")
    public ResponseEntity<Void> removerLivro(@PathVariable int id) {
        livroService.removerLivro(id);
        return ResponseEntity.noContent().build();
    }

    @PutMapping("/livros/{id}")
    public ResponseEntity<Livro> atualizarLivro(@PathVariable int id, @RequestBody Livro livroAtualizado) {
        Livro livro = livroService.atualizarLivro(id, livroAtualizado);
        return ResponseEntity.ok(livro);
    }     
}
