#ifndef INC_2024_PROJECT_VIKI_LAUVRYS_OBSERVER_H
#define INC_2024_PROJECT_VIKI_LAUVRYS_OBSERVER_H

namespace DOODLE_JUMP::Logic {

    /**
     * \class Observer
     * \brief Abstract base class for observers in the observer pattern.
     *
     * The Observer class provides an interface for objects that should be notified of changes in the subject they are observing.
     */
    class Observer {
    public:
        /**
         * \brief Virtual destructor for Observer.
         */
        virtual ~Observer() = default;

        /**
         * \brief Pure virtual function to update the observer.
         *
         * This function is called to notify the observer of changes in the subject.
         */
        virtual void update() = 0;
    };
}

#endif // INC_2024_PROJECT_VIKI_LAUVRYS_OBSERVER_H