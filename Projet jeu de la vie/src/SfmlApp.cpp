#include "SfmlApp.h"
#include <optional>        

SfmlApp::SfmlApp(int width, int height, float cellSize, float stepDelaySeconds)
    : m_window(
        sf::VideoMode(sf::Vector2u(
            static_cast<unsigned int>(width* cellSize),
            static_cast<unsigned int>(height* cellSize))),
        "Jeu de la Vie - SFML")
    , m_game(width, height, std::make_unique<ConwayRule>())
    , m_renderer(m_game, cellSize)
    , m_stepDelay(stepDelaySeconds)
{
    m_window.setFramerateLimit(60);
    m_game.randomize();
}

void SfmlApp::run()
{
    bool paused = false;
    sf::Clock clock;
    float accumulator = 0.0f;

    while (m_window.isOpen())
    {
        // temps écoulé depuis la frame précédente
        float dt = clock.restart().asSeconds();
        accumulator += dt;

        bool doStep = false; 

        // ---------- Gestion des événements ----------
        while (const std::optional<sf::Event> event = m_window.pollEvent())
        {
            if (!event)
                continue;

            // Fermeture fenêtre
            if (event->is<sf::Event::Closed>())
                m_window.close();

            // Touches pressées
            if (auto* key = event->getIf<sf::Event::KeyPressed>())
            {
                switch (key->code)
                {
                case sf::Keyboard::Key::Space:   // pause / reprise
                    paused = !paused;
                    break;

                case sf::Keyboard::Key::R:       // re-générer aléatoirement
                    m_game.randomize();
                    break;

                case sf::Keyboard::Key::C:       // clear
                    m_game.clear();
                    break;

                case sf::Keyboard::Key::N:       // une étape manuelle
                    doStep = true;
                    break;

                default:
                    break;
                }
            }
        }

        // ---------- Avance automatique ----------
        if (!paused && accumulator >= m_stepDelay)
        {
            doStep = true;
            accumulator = 0.0f;
        }

        if (doStep)
            m_game.step();

        // ---------- Rendu ----------
        m_window.clear(sf::Color::Black);
        m_renderer.draw(m_window);
        m_window.display();
    }
}
