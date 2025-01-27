#ifndef INC_2024_PROJECT_VIKI_LAUVRYS_ENTITY_H
#define INC_2024_PROJECT_VIKI_LAUVRYS_ENTITY_H

#include <iostream>
#include <memory>
#include "../RANDOM/Random.h"

namespace DOODLE_JUMP::Logic {

    /**
     * \class Entity
     * \brief Represents a generic entity in the game.
     *
     * The Entity class provides basic functionality for game entities, including movement and position.
     */
    class Entity {
    public:
        /**
         * \brief Default constructor for Entity.
         */
        Entity() = default;

        /**
         * \brief Virtual destructor for Entity.
         */
        virtual ~Entity() = default;

        /**
         * \brief Moves the entity by a specified amount.
         * \param dx The amount to move in the x direction.
         * \param dy The amount to move in the y direction.
         */
        virtual void move(float dx, float dy) = 0;

        /**
         * \brief Gets the x position of the entity.
         * \return The x position of the entity.
         */
        virtual float getX() = 0;

        /**
         * \brief Gets the y position of the entity.
         * \return The y position of the entity.
         */
        virtual float getY() = 0;

        int x{}, y{}; ///< The position of the entity.

        float jumpHeight = 2.0f; ///< The jump height of the entity.

        /**
         * \brief Gets the jump height of the entity.
         * \return The jump height of the entity.
         */
        [[nodiscard]] float getJumpHeight() const {
            return jumpHeight;
        }

        /**
         * \brief Sets the jump height of the entity.
         * \param newJumpHeight The new jump height.
         */
        void setJumpHeight(float newJumpHeight) {
            this->jumpHeight = newJumpHeight;
        }
    };

    /**
     * \class BonusStrategy
     * \brief Represents a strategy for applying and removing bonuses.
     */
    class BonusStrategy {
    protected:
        std::string textureName; ///< The texture name for the bonus.
        float score; ///< The extra score this bonus gives.

    public:
        /**
         * \brief Applies the bonus to an entity.
         * \param entity The entity to apply the bonus to.
         */
        virtual void apply(Entity& entity) = 0;

        /**
         * \brief Removes the bonus from an entity.
         * \param entity The entity to remove the bonus from.
         */
        virtual void remove(Entity& entity) = 0;

        /**
         * \brief Virtual destructor for BonusStrategy.
         */
        virtual ~BonusStrategy() = default;

        /**
         * \brief Gets the texture name of the bonus.
         * \return The texture name.
         */
        std::string getTextureName() {
            return textureName;
        }

        /**
         * \brief Gets the score of the bonus.
         * \return The score.
         */
        [[nodiscard]] float getScore() const {
            return score;
        }
    };
}

#endif //INC_2024_PROJECT_VIKI_LAUVRYS_ENTITY_H