#include "raylib.h"
#include "EntityManager.hpp"







struct PlayerConfig { float SP, CR, FR, ETC; int S;};
struct EnemyConfig { float SP, CR, FR, ETC; int S;};
struct BulletConfig { float SP, CR, FR, ETC; int S;};

class Game
{
    EntityManager   m_entities;
    Font            m_font;
    PlayerConfig    m_playerConfig;
    EnemyConfig     m_enemyConfig;
    BulletConfig    m_bulletConfig;
    int             m_score = 0;
    int             m_currentFrame = 0;
    int             m_lastEnemySpawnFrame = 0;
    bool            m_paused = false;
    bool            m_running = true;

    void init(const std::string & config);
    void setPaused(bool paused);

    void sMovement();
    void sUserInput();
    void sLifeSpan();
    void sRender();
    void sGUI();
    void sEnemySpawn();
    void SCollision();

    void spawnPlayer();
    void spawnEnemy();
    void spawnSmallEnemy(std::shared_ptr<Entity> entity);
    void spawnBullet(std::shared_ptr<Entity> entity, const Vec2f & mousePos);
    void spawnSpecialWeapon(std::shared_ptr<Entity> entity);

    std::shared_ptr<Entity> player();

public:

    Game(const std::string & config);
    void run();

};