#ifndef INC_2024_PROJECT_VIKI_LAUVRYS_ENTITYMODEL_H
#define INC_2024_PROJECT_VIKI_LAUVRYS_ENTITYMODEL_H

#include <memory>
#include "../ENTITY/Entity.h"
#include "../PLAYER/Player.h"
#include "../PLATFORM/Platform.h"

namespace DOODLE_JUMP::Logic {

    /**
     * \class EntityModel
     * \brief Abstract base class for creating entities.
     *
     * The EntityModel class provides a factory method for creating entities.
     */
    class EntityModel {
    public:
        /**
         * \brief Factory method for creating an entity.
         * \return A shared pointer to the created entity.
         */
        virtual std::shared_ptr<Entity> FactoryMethod() = 0;

        /**
         * \brief Creates an entity object using the factory method.
         * \return A shared pointer to the created entity.
         */
        [[nodiscard]] std::shared_ptr<Entity> createObject();

        /**
         * \brief Virtual destructor for EntityModel.
         */
        virtual ~EntityModel() = default;
    };

    /**
     * \class PlayerCreator
     * \brief Concrete creator for Player entities.
     */
    class PlayerCreator : public EntityModel {
        /**
         * \brief Factory method for creating a Player entity.
         * \return A shared pointer to the created Player entity.
         */
        [[nodiscard]] std::shared_ptr<Entity> FactoryMethod() override;
    };

    /**
     * \class PlatformStaticCreator
     * \brief Concrete creator for static Platform entities.
     */
    class PlatformStaticCreator : public EntityModel {
        /**
         * \brief Factory method for creating a static Platform entity.
         * \return A shared pointer to the created static Platform entity.
         */
        [[nodiscard]] std::shared_ptr<Entity> FactoryMethod() override;
    };

    /**
     * \class PlatformHorizontalCreator
     * \brief Concrete creator for horizontal moving Platform entities.
     */
    class PlatformHorizontalCreator : public EntityModel {
        /**
         * \brief Factory method for creating a horizontal moving Platform entity.
         * \return A shared pointer to the created horizontal moving Platform entity.
         */
        [[nodiscard]] std::shared_ptr<Entity> FactoryMethod() override;
    };

    /**
     * \class PlatformVerticalCreator
     * \brief Concrete creator for vertical moving Platform entities.
     */
    class PlatformVerticalCreator : public EntityModel {
        /**
         * \brief Factory method for creating a vertical moving Platform entity.
         * \return A shared pointer to the created vertical moving Platform entity.
         */
        [[nodiscard]] std::shared_ptr<Entity> FactoryMethod() override;
    };

    /**
     * \class PlatformTemporaryCreator
     * \brief Concrete creator for temporary Platform entities.
     */
    class PlatformTemporaryCreator : public EntityModel {
        /**
         * \brief Factory method for creating a temporary Platform entity.
         * \return A shared pointer to the created temporary Platform entity.
         */
        [[nodiscard]] std::shared_ptr<Entity> FactoryMethod() override;
    };

    /**
     * \class BonusCreator
     * \brief Concrete creator for Bonus entities.
     */
    class BonusCreator : public EntityModel {
        /**
         * \brief Factory method for creating a Bonus entity.
         * \return A shared pointer to the created Bonus entity.
         */
        [[nodiscard]] std::shared_ptr<Entity> FactoryMethod() override;
    };

}

#endif //INC_2024_PROJECT_VIKI_LAUVRYS_ENTITYMODEL_H