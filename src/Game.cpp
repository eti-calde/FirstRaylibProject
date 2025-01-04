#include "Game.h"
#include "iostream"
#include <cassert>

Game::Game(const std::string & config)
{
    init(config);
}

void Game::init(const std::string & path)
{
    //TODO: read in config file
    // use the premade config file to set up the game

    // set up default window parameters
    // set screen
    // set frame rate

    // set up styles

    spawnPlayer();
}

std::shared_ptr<Entity> Game::player()
{
    auto& players = m_entities.getEntitiesByTag("player");
    assert(players.size() == 1);

    return players.front();
}

void Game::run()
{
    //TODO: add pause functionality here
    // some systems should not run when paused (rendering)
    while (m_running)
    {
        //m_entities.update();

        //search if need to call update func from raylib

        //sEnemySpawn();
        //sMovement();
        //SCollision();
        //sUserInput();
        //sGUI();
        sRender();

        m_currentFrame++;
    }
}

void Game::spawnPlayer()
{
    //TODO finish add all properties of the payer 

    auto playerEntity = m_entities.addEntity("player");

    Vec2f pPosition  = {0.0, 0.0};
    Vec2f pVelocity  = {0.0, 0.0};
    float pAngle     = 0;

    playerEntity->add<CTransform>(pPosition, pVelocity, pAngle);

    playerEntity->add<CShape>(pPosition, 3, 10.0, 0.0, GREEN);
    
    playerEntity->add<CInput>();
}

void Game::spawnEnemy()
{
    //TODO: make sure the enemy is spawned properly

    // record when the most recent enemy was spawned
    m_lastEnemySpawnFrame = m_currentFrame;
}

void Game::spawnSmallEnemy(std::shared_ptr<Entity> entity)
{
    //TODO: spawn small enemies at when a big enemy dies
}

void Game::spawnBullet(std::shared_ptr<Entity> entity, const Vec2f & mousePos)
{
    //TODO: make sure the bullet is spawned properly
}

void Game::spawnSpecialWeapon(std::shared_ptr<Entity> entity)
{

}

void Game::sMovement()
{
    auto& transform = player()->get<CTransform>();
    transform.position += transform.velocity;
}

void Game::sLifeSpan()
{
    //TODO
    //for all entities
    //  if entity has life span component
    //     decrement remaining life span if > 0
    //     if has spanlife and is alive
    //       scale alpha channel
    //     if remaining life span is 0
    //       remove entity
}

void Game::SCollision()
{
    //TODO
}   

void Game::sEnemySpawn()
{
    //TODO
    //if current frame - last enemy spawn frame > enemy spawn rate
    //  spawn enemy
}

void Game::sGUI()
{
    //TODO
    //draw score
    //draw health
    //draw special weapon
    //draw pause button
}

void Game:: sRender()
{


}

void Game:: sUserInput()
{
    //TODO
    //if key is pressed
    //  if key is space
    //    spawn bullet
    //  if key is special weapon key
    //    spawn special weapon
    //  if key is pause key
    //    set paused
    //  if key is quit key
    //    set running to false
    //if mouse is pressed
    //  if mouse is left button
    //    spawn bullet
    //  if mouse is right button
    //    spawn special weapon
    //if mouse is moved
    //  set player velocity to mouse position
    //if mouse is scrolled
    //  change player rotation
}