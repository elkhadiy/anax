///
/// anax
/// Copyright (C) 2013 Miguel Martin (miguel.martin7.5@hotmail.com)
///
///
/// This software is provided 'as-is', without any express or implied warranty.
/// In no event will the authors be held liable for any damages arising from the
/// use of this software.
///
/// Permission is hereby granted, free of charge, to any person
/// obtaining a copy of this software and associated documentation files (the "Software"),
/// to deal in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
///
/// 1. The origin of this software must not be misrepresented;
///    you must not claim that you wrote the original software.
///    If you use this software in a product, an acknowledgment
///    in the product documentation would be appreciated but is not required.
///
/// 2. Altered source versions must be plainly marked as such,
///	   and must not be misrepresented as being the original software.
///
/// 3. The above copyright notice and this permission notice shall be included in
///    all copies or substantial portions of the Software.
///

#ifndef __ANAX_ENTITYCOMPONENTSTORAGE_HPP__
#define __ANAX_ENTITYCOMPONENTSTORAGE_HPP__

#include <vector>

#include "config.hpp"
#include "Entity.hpp"
#include "Component.hpp"
#include "ComponentTypeList.hpp"

namespace anax
{
	namespace detail
	{
		/// \brief A class to store components for entities within a world
		///
		///
		/// Used to store the components 
		///
		///
		/// \author Miguel Martin
		class EntityComponentStorage
		{
		public:
			
			EntityComponentStorage();
			
			EntityComponentStorage(const EntityComponentStorage&) = delete;
			EntityComponentStorage(EntityComponentStorage&&) = delete;
			EntityComponentStorage& operator=(const EntityComponentStorage&) = delete;
			EntityComponentStorage& operator=(EntityComponentStorage&&) = delete;
						
			void addComponent(Entity& entity, BaseComponent* component);
			
			void removeComponent(Entity& entity, BaseComponent* component);
			
			void removeComponent(Entity& entity, TypeId componentTypeId);
			
			BaseComponent* getComponent(const Entity& entity, TypeId componentTypeId) const;
			
			ComponentTypeList getComponentTypeList(const Entity& entity) const;
			
			const std::vector<BaseComponent*>& getComponents(const Entity& entity) const;
			
			bool hasComponent(const Entity& entity, TypeId componentTypeId) const;
			
		private:
			
			/// \brief A data structure to describe the components
			/// within an entity
			/// 
			/// \author Miguel Martin
			struct EntityComponents
			{
				/// The components of an entity. The
				/// index of this array is the same as the TypeId
				/// of the component.
				std::vector<BaseComponent*> components;
				
				/// A list of component types, which resembles
				/// what components an entity has
				ComponentTypeList componentTypeList;
			};
			
			/// All the components for every entity, which has
			/// an entity. The indices of this array is the same
			/// as the index component of an entity's ID.
			std::vector<EntityComponents> _componentEntries;
		};
	}
}


#endif // __ANAX_ENTITYATTRIBUTES_HPP__