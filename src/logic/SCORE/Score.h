#ifndef INC_2024_PROJECT_VIKI_LAUVRYS_SCORE_H
#define INC_2024_PROJECT_VIKI_LAUVRYS_SCORE_H

#include "../OBSERVER/Observer.h"
#include <utility> // Include this for std::pair

namespace DOODLE_JUMP::Logic {

    /**
     * \class Score
     * \brief Manages the player's score in the game.
     *
     * The Score class provides functionality for tracking, updating, and retrieving the player's score.
     */
    class Score : public Observer {
    private:
        float score; ///< The current score of the player.

    public:
        /**
         * \brief Default constructor for Score.
         */
        Score() noexcept;

        /**
         * \brief Increments the player's score.
         */
        void incrementScore();

        /**
         * \brief Gets the current score of the player.
         * \return The current score.
         */
        [[nodiscard]] int getScore() const;

        /**
         * \brief Resets the player's score to zero.
         */
        void resetScore();

        /**
         * \brief Updates the score based on game events.
         */
        void update() override;

        /**
         * \brief Gets the high and low scores.
         * \return A pair containing the high score and low score.
         */
        static std::pair<int, int> getScores();

        /**
         * \brief Checks if the current score is a new high score.
         * \return True if the current score is a new high score, false otherwise.
         */
        [[nodiscard]] bool isNewHighScore() const;

        /**
         * \brief Checks if the current score is a new low score.
         * \return True if the current score is a new low score, false otherwise.
         */
        [[nodiscard]] bool isNewLowScore() const;

        /**
         * \brief Saves the current score.
         */
        void saveScore() const;

        /**
         * \brief Decrements the player's score by a specified amount.
         * \param amount The amount to decrement the score by.
         */
        void decrementScore(float amount);

        /**
         * \brief Gets the high score.
         * \return The high score.
         */
        static int getHighScore();

        /**
         * \brief Gets the low score.
         * \return The low score.
         */
        static int getLowScore();

        /**
         * \brief Adds a bonus score to the player's current score.
         * \param bonusScore The amount of bonus score to add.
         */
        void addBonusScore(float bonusScore);
    };
}

#endif //INC_2024_PROJECT_VIKI_LAUVRYS_SCORE_H