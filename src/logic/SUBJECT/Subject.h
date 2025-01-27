#ifndef INC_2024_PROJECT_VIKI_LAUVRYS_SUBJECT_H
#define INC_2024_PROJECT_VIKI_LAUVRYS_SUBJECT_H

#include <vector>
#include <memory>
#include "../OBSERVER/Observer.h"

namespace DOODLE_JUMP::Logic {

    /**
     * \class Subject
     * \brief Manages a list of observers and notifies them of changes.
     *
     * The Subject class provides functionality to attach, detach, and notify observers.
     */
    class Subject {
    public:
        /**
         * \brief Attaches an observer to the subject.
         * \param observer The observer to attach.
         */
        void attach(std::shared_ptr<Observer> observer);

        /**
         * \brief Detaches an observer from the subject.
         * \param observer The observer to detach.
         */
        void detach(std::shared_ptr<Observer> observer);

        /**
         * \brief Notifies all attached observers of a change.
         */
        void notifyObservers();

    protected:
        bool changed = false; ///< Flag indicating if the subject has changed.

    private:
        std::vector<std::shared_ptr<Observer>> observers; ///< List of attached observers.
    };
}

#endif // INC_2024_PROJECT_VIKI_LAUVRYS_SUBJECT_H