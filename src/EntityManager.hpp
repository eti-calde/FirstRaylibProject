#pragma once

#include "Entity.hpp"
#include <vector>
#include <memory>
#include <map>


using EntityVec = std::vector<std::shared_ptr<Entity>>;

class EntityManager
{
    EntityVec                           m_entities;
    EntityVec                           m_entitiesToAdd;
    std::map<std::string, EntityVec>    m_entityMap;
    size_t                              m_totalEntities = 0;    

    void removeDeadEntities(EntityVec& vec)
    {
        //TODO
    }
public:
    EntityManager() = default;

    void update()
    {
        //TODO: add entities from m_entitiesToAdd to
        //  - add the to the vector of all entities
        //  - add them to the map of entities by tag

        //remove dead entities
        removeDeadEntities(m_entities);

        //remove dead entities from the map
        //C++ 20 way of iterating through [key,value] pairs in a map
        for (auto& [tag, entityVec] : m_entityMap)
        {
            removeDeadEntities(entityVec);
        } 
    }

    std::shared_ptr<Entity> addEntity(const std::string& tag)
    {
        // create the entity shared pointer
        auto entity = std::shared_ptr<Entity>(new Entity(m_totalEntities++, tag));

        // add it to the vec of al entitites
        m_entitiesToAdd.push_back(entity);

        // add it to the map of entities by tag
        if (m_entityMap.find(tag) == m_entityMap.end())
        {
            m_entityMap[tag] = EntityVec();
        }
        m_entityMap[tag].push_back(entity);

        return entity;
    }

    const EntityVec& getEntities()
    {
        return m_entities;
    }

    const EntityVec& getEntitiesByTag(const std::string& tag)
    {
        if (m_entityMap.find(tag) == m_entityMap.end())
        {
            m_entityMap[tag] = EntityVec();
        }
        return m_entityMap[tag];
    }

    const std::map<std::string, EntityVec>& getEntityMap()
    {
        return m_entityMap;
    }
};