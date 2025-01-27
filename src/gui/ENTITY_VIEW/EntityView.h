#ifndef INC_2024_PROJECT_VIKI_LAUVRYS_ENTITYVIEW_H
#define INC_2024_PROJECT_VIKI_LAUVRYS_ENTITYVIEW_H

#include "../../logic/ENTITY/Entity.h"
#include <memory>
#include <utility>

namespace DOODLE_JUMP::View {

    /**
     * \class EntityView
     * \brief Abstract base class for rendering entities in the game.
     */
    class EntityView {
    protected:
        std::shared_ptr<Logic::Entity> model; ///< The model representing the entity.

    public:
        /**
         * \brief Constructor for EntityView.
         * \param entity A shared pointer to the entity model.
         */
        explicit EntityView(std::shared_ptr<Logic::Entity> entity) : model(std::move(entity)) {}

        /**
         * \brief Virtual destructor for EntityView.
         */
        virtual ~EntityView() = default;

        /**
         * \brief Pure virtual function to render the entity.
         */
        virtual void render() = 0;
    };
}

#endif //INC_2024_PROJECT_VIKI_LAUVRYS_ENTITYVIEW_H