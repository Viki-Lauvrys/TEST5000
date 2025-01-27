#ifndef INC_2024_PROJECT_VIKI_LAUVRYS_BONUSSTRATEGY_H
#define INC_2024_PROJECT_VIKI_LAUVRYS_BONUSSTRATEGY_H

namespace DOODLE_JUMP::Logic {

    /**
     * \class JumpBonus
     * \brief Represents a jump bonus strategy.
     *
     * This bonus allows the player to jump 5 times as high.
     */
    class JumpBonus : public BonusStrategy {
    private:
        float jumpIncrease = 5.0f; ///< Multiplier for jump height.

    public:
        /**
         * \brief Constructor for JumpBonus.
         */
        JumpBonus() {
            textureName = "platformTexBonus1";
            score = 500; ///< The extra score this bonus gives.
        }

        /**
         * \brief Applies the jump bonus to an entity.
         * \param entity The entity to apply the bonus to.
         */
        void apply(Entity& entity) override {
            entity.setJumpHeight(jumpIncrease);
        }

        /**
         * \brief Removes the jump bonus from an entity.
         * \param entity The entity to remove the bonus from.
         */
        void remove(Entity& entity) override {
            entity.setJumpHeight(1.0f); // Reset to normal
        }
    };

    /**
     * \class JetPackBonus
     * \brief Represents a jetpack bonus strategy.
     *
     * This bonus allows the player to jump 10 times as high.
     */
    class JetPackBonus : public BonusStrategy {
    private:
        float jumpIncrease = 10.0f; ///< Multiplier for jump height.

    public:
        /**
         * \brief Constructor for JetPackBonus.
         */
        JetPackBonus() {
            textureName = "platformTexBonus2";
            score = 1000; ///< The extra score this bonus gives.
        }

        /**
         * \brief Applies the jetpack bonus to an entity.
         * \param entity The entity to apply the bonus to.
         */
        void apply(Entity& entity) override {
            entity.setJumpHeight(jumpIncrease);
        }

        /**
         * \brief Removes the jetpack bonus from an entity.
         * \param entity The entity to remove the bonus from.
         */
        void remove(Entity& entity) override {
            entity.setJumpHeight(1.0f); // Reset to normal
        }
    };

    /**
     * \brief Gets a random bonus strategy.
     * \return A shared pointer to a random bonus strategy.
     */
    std::shared_ptr<BonusStrategy> getRandomBonusStrategy() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 1); // Adjust range based on the number of strategies

        switch (dis(gen)) {
            case 0:
                return std::make_shared<JumpBonus>();
            default: // case 1
                return std::make_shared<JetPackBonus>();
        }
    }

}

#endif //INC_2024_PROJECT_VIKI_LAUVRYS_BONUSSTRATEGY_H