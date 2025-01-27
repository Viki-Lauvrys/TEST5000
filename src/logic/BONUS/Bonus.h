#ifndef INC_2024_PROJECT_VIKI_LAUVRYS_BONUS_H
#define INC_2024_PROJECT_VIKI_LAUVRYS_BONUS_H

namespace DOODLE_JUMP::Logic {

    /**
     * \class Bonus
     * \brief Represents a bonus entity in the game.
     *
     * The Bonus class is responsible for applying and removing bonus effects on entities.
     */
    class Bonus : public Entity {
    public:
        /**
         * \brief Constructor for Bonus.
         * \param strategy A shared pointer to the bonus strategy.
         */
        explicit Bonus(std::shared_ptr<BonusStrategy> strategy) : strategy_(std::move(strategy)) {}

        /**
         * \brief Applies the bonus effect to an entity.
         * \param entity The entity to apply the bonus to.
         */
        void apply(Entity& entity) {
            strategy_->apply(entity);
        }

        /**
         * \brief Removes the bonus effect from an entity.
         * \param entity The entity to remove the bonus from.
         */
        void remove(Entity& entity) {
            strategy_->remove(entity);
        }

        /**
         * \brief Moves the bonus by a specified amount.
         * \param dx The amount to move in the x direction.
         * \param dy The amount to move in the y direction.
         */
        void move(float dx, float dy) override {
            x += dx;
            y += dy;
        }

        /**
         * \brief Gets the x position of the bonus.
         * \return The x position of the bonus.
         */
        float getX() override {
            return Camera::translateY(x);
        }

        /**
         * \brief Gets the y position of the bonus.
         * \return The y position of the bonus.
         */
        float getY() override {
            return Camera::translateY(y);
        }

        /**
         * \brief Sets the x position of the bonus.
         * \param newX The new x position.
         */
        void setX(float newX) {
            this->x = newX;
        }

        /**
         * \brief Sets the y position of the bonus.
         * \param newY The new y position.
         */
        void setY(float newY) {
            this->y = newY;
        }

        /**
         * \brief Gets the texture name of the bonus.
         * \return The texture name.
         */
        std::string getTextureName() {
            return strategy_->getTextureName();
        }

        /**
         * \brief Gets the score of the bonus.
         * \return The score.
         */
        float getScore() {
            return strategy_->getScore();
        }

    private:
        std::shared_ptr<BonusStrategy> strategy_; ///< The strategy for the bonus.
        float x{}, y{}; ///< The position of the bonus.
        float score = 0; ///< The extra score this bonus gives.
    };
}

#endif // INC_2024_PROJECT_VIKI_LAUVRYS_BONUS_H