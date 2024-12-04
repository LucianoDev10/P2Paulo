#include "raylib.h"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Item.hpp"
#include <vector>

int main() {
    // Inicialização da janela
    InitWindow(800, 600, "Jogo do Jogador e Itens");
    
    // Criar o jogador
    Player player(400, 300, 20);

    // Criar inimigos
    std::vector<Enemy> enemies;
    enemies.push_back(Enemy(700, 200, 30));
    enemies.push_back(Enemy(750, 400, 30));

    // Criar itens
    std::vector<Item> items;
    items.push_back(Item(500, 100, 15, 10));  // Item 1
    items.push_back(Item(600, 200, 15, 20));  // Item 2

    SetTargetFPS(60); // Limitar a 60 FPS

    while (!WindowShouldClose()) {
        // Lógica de movimentação do jogador
        player.Move();

        // Atualizar inimigos
        for (auto &enemy : enemies) {
            enemy.Update();
        }

        // Verificar colisões de itens
        for (auto &item : items) {
            if (item.CheckCollision(player.position, player.radius)) {
                player.CollectItem(item.scoreValue);
                item.Destroy();  // Destruir o item após ser coletado
            }
        }

        // Desenho na tela
        BeginDrawing();
        ClearBackground(BLACK);
        
        // Desenhar o jogador, inimigos e itens
        player.Draw();
        for (auto &enemy : enemies) {
            enemy.Draw();
        }
        for (auto &item : items) {
            item.Draw();
        }

        // Exibir a pontuação
        DrawText(TextFormat("Score: %i", player.score), 10, 10, 20, WHITE);

        EndDrawing();
    }

    CloseWindow(); // Fechar janela

    return 0;
}
