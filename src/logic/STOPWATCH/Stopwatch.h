#ifndef INC_2024_PROJECT_VIKI_LAUVRYS_STOPWATCH_H
#define INC_2024_PROJECT_VIKI_LAUVRYS_STOPWATCH_H

#include <chrono>
#include <memory>

namespace DOODLE_JUMP::Logic {

    /**
     * \class Stopwatch
     * \brief A simple stopwatch class for measuring elapsed time.
     *
     * The Stopwatch class provides functionality to start, stop, reset, and get the elapsed time.
     */
    class Stopwatch {
    public:
        /**
         * \brief Gets the singleton instance of the Stopwatch.
         * \return The singleton instance of the Stopwatch.
         */
        static Stopwatch& getInstance() {
            static Stopwatch instance;
            return instance;
        }

        /**
         * \brief Starts the stopwatch.
         */
        void start();

        /**
         * \brief Stops the stopwatch.
         */
        void stop();

        /**
         * \brief Resets the stopwatch.
         */
        void reset();

        /**
         * \brief Gets the elapsed time in seconds.
         * \return The elapsed time in seconds.
         */
        double getElapsedTime() const;

        // Private constructor to prevent instantiation
        Stopwatch() = default;

    private:
        // Delete copy constructor and assignment operator to prevent copying
        Stopwatch(const Stopwatch&) = delete;
        Stopwatch& operator=(const Stopwatch&) = delete;

        std::chrono::time_point<std::chrono::high_resolution_clock> startTime; ///< The start time of the stopwatch.
        std::chrono::time_point<std::chrono::high_resolution_clock> endTime; ///< The end time of the stopwatch.
        bool running = false; ///< Flag indicating if the stopwatch is running.
    };
}
#endif // INC_2024_PROJECT_VIKI_LAUVRYS_STOPWATCH_H