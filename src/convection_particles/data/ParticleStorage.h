//======================================================================================================================
//
//  This file is part of waLBerla. waLBerla is free software: you can
//  redistribute it and/or modify it under the terms of the GNU General Public
//  License as published by the Free Software Foundation, either version 3 of
//  the License, or (at your option) any later version.
//
//  waLBerla is distributed in the hope that it will be useful, but WITHOUT
//  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
//  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
//  for more details.
//
//  You should have received a copy of the GNU General Public License along
//  with waLBerla (see COPYING.txt). If not, see <http://www.gnu.org/licenses/>.
//
//! \file ParticleStorage.h
//! \author Sebastian Eibl <sebastian.eibl@fau.de>
//
//======================================================================================================================

//======================================================================================================================
//
//  THIS FILE IS GENERATED - PLEASE CHANGE THE TEMPLATE !!!
//
//======================================================================================================================

#pragma once

#include <atomic>
#include <limits>
#include <map>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <convection_particles/data/ContactHistory.h>
#include <convection_particles/data/DataTypes.h>
#include <convection_particles/data/IAccessor.h>
#include <convection_particles/data/Flags.h>
#include <blockforest/BlockForest.h>
#include <convection_particles/data/STLOverloads.h>

#include <core/Abort.h>
#include <core/debug/Debug.h>
#include <core/math/AABB.h>
#include <core/mpi/MPIWrapper.h>
#include <core/OpenMP.h>
#include <core/STLIO.h>
#include <core/UniqueID.h>

namespace walberla {
namespace convection_particles {
namespace data {

class ParticleStorage;

class ParticleStorage
{
public:
   class Particle
   {
   public:
      constexpr Particle(ParticleStorage& storage, const size_t i) : storage_(storage), i_(i) {}
      constexpr Particle(const Particle&)  = default;
      constexpr Particle(Particle&&)  = default;

      Particle& operator=(const Particle& rhs);
      Particle& operator=(Particle&& rhs);

      Particle* operator->(){return this;}

      
      using uid_type = walberla::id_t;
      using position_type = walberla::convection_particles::Vec3;
      using interactionRadius_type = walberla::real_t;
      using flags_type = walberla::convection_particles::data::particle_flags::FlagT;
      using owner_type = int;
      using ghostOwners_type = std::unordered_set<walberla::mpi::MPIRank>;
      using velocity_type = walberla::convection_particles::Vec3;
      using currentBlock_type = blockforest::BlockID;
      using neighborState_type = std::unordered_set<walberla::mpi::MPIRank>;

      
      uid_type const & getUid() const {return storage_.getUid(i_);}
      uid_type& getUidRef() {return storage_.getUidRef(i_);}
      void setUid(uid_type const & v) { storage_.setUid(i_, v);}
      
      position_type const & getPosition() const {return storage_.getPosition(i_);}
      position_type& getPositionRef() {return storage_.getPositionRef(i_);}
      void setPosition(position_type const & v) { storage_.setPosition(i_, v);}
      
      interactionRadius_type const & getInteractionRadius() const {return storage_.getInteractionRadius(i_);}
      interactionRadius_type& getInteractionRadiusRef() {return storage_.getInteractionRadiusRef(i_);}
      void setInteractionRadius(interactionRadius_type const & v) { storage_.setInteractionRadius(i_, v);}
      
      flags_type const & getFlags() const {return storage_.getFlags(i_);}
      flags_type& getFlagsRef() {return storage_.getFlagsRef(i_);}
      void setFlags(flags_type const & v) { storage_.setFlags(i_, v);}
      
      owner_type const & getOwner() const {return storage_.getOwner(i_);}
      owner_type& getOwnerRef() {return storage_.getOwnerRef(i_);}
      void setOwner(owner_type const & v) { storage_.setOwner(i_, v);}
      
      ghostOwners_type const & getGhostOwners() const {return storage_.getGhostOwners(i_);}
      ghostOwners_type& getGhostOwnersRef() {return storage_.getGhostOwnersRef(i_);}
      void setGhostOwners(ghostOwners_type const & v) { storage_.setGhostOwners(i_, v);}
      
      velocity_type const & getVelocity() const {return storage_.getVelocity(i_);}
      velocity_type& getVelocityRef() {return storage_.getVelocityRef(i_);}
      void setVelocity(velocity_type const & v) { storage_.setVelocity(i_, v);}
      
      currentBlock_type const & getCurrentBlock() const {return storage_.getCurrentBlock(i_);}
      currentBlock_type& getCurrentBlockRef() {return storage_.getCurrentBlockRef(i_);}
      void setCurrentBlock(currentBlock_type const & v) { storage_.setCurrentBlock(i_, v);}
      
      neighborState_type const & getNeighborState() const {return storage_.getNeighborState(i_);}
      neighborState_type& getNeighborStateRef() {return storage_.getNeighborStateRef(i_);}
      void setNeighborState(neighborState_type const & v) { storage_.setNeighborState(i_, v);}
      

      size_t getIdx() const {return i_;}
   public:
      ParticleStorage& storage_;
      const size_t i_;
   };

   class iterator
   {
   public:
      using iterator_category = std::random_access_iterator_tag;
      using value_type        = Particle;
      using pointer           = Particle*;
      using reference         = Particle&;
      using difference_type   = std::ptrdiff_t;

      explicit iterator(ParticleStorage* storage, const size_t i) : storage_(storage), i_(i) {}
      iterator(const iterator& it)         = default;
      iterator(iterator&& it)              = default;
      iterator& operator=(const iterator&) = default;
      iterator& operator=(iterator&&)      = default;


      Particle operator*() const {return Particle{*storage_, i_};}
      Particle operator->() const {return Particle{*storage_, i_};}
      iterator& operator++(){ ++i_; return *this; }
      iterator operator++(int){ iterator tmp(*this); ++(*this); return tmp; }
      iterator& operator--(){ --i_; return *this; }
      iterator operator--(int){ iterator tmp(*this); --(*this); return tmp; }

      iterator& operator+=(const size_t n){ i_+=n; return *this; }
      iterator& operator-=(const size_t n){ i_-=n; return *this; }

      friend iterator operator+(const iterator& it, const size_t n);
      friend iterator operator+(const size_t n, const iterator& it);
      friend iterator operator-(const iterator& it, const size_t n);
      friend difference_type operator-(const iterator& lhs, const iterator& rhs);

      friend bool operator==(const iterator& lhs, const iterator& rhs);
      friend bool operator!=(const iterator& lhs, const iterator& rhs);
      friend bool operator<(const iterator& lhs, const iterator& rhs);
      friend bool operator>(const iterator& lhs, const iterator& rhs);
      friend bool operator<=(const iterator& lhs, const iterator& rhs);
      friend bool operator>=(const iterator& lhs, const iterator& rhs);

      friend void swap(iterator& lhs, iterator& rhs);

      size_t getIdx() const {return i_;}
   private:
      ParticleStorage* storage_;
      size_t i_;
   };

   explicit ParticleStorage(const size_t size);

   iterator begin() { return iterator(this, 0); }
   iterator end()   { return iterator(this, size()); }
   Particle operator[](const size_t n) { return *iterator(this, n); }

   
   using uid_type = walberla::id_t;
   using position_type = walberla::convection_particles::Vec3;
   using interactionRadius_type = walberla::real_t;
   using flags_type = walberla::convection_particles::data::particle_flags::FlagT;
   using owner_type = int;
   using ghostOwners_type = std::unordered_set<walberla::mpi::MPIRank>;
   using velocity_type = walberla::convection_particles::Vec3;
   using currentBlock_type = blockforest::BlockID;
   using neighborState_type = std::unordered_set<walberla::mpi::MPIRank>;

   
   uid_type const & getUid(const size_t idx) const {return uid_[idx];}
   uid_type& getUidRef(const size_t idx) {return uid_[idx];}
   void setUid(const size_t idx, uid_type const & v) { uid_[idx] = v; }
   
   position_type const & getPosition(const size_t idx) const {return position_[idx];}
   position_type& getPositionRef(const size_t idx) {return position_[idx];}
   void setPosition(const size_t idx, position_type const & v) { position_[idx] = v; }
   
   interactionRadius_type const & getInteractionRadius(const size_t idx) const {return interactionRadius_[idx];}
   interactionRadius_type& getInteractionRadiusRef(const size_t idx) {return interactionRadius_[idx];}
   void setInteractionRadius(const size_t idx, interactionRadius_type const & v) { interactionRadius_[idx] = v; }
   
   flags_type const & getFlags(const size_t idx) const {return flags_[idx];}
   flags_type& getFlagsRef(const size_t idx) {return flags_[idx];}
   void setFlags(const size_t idx, flags_type const & v) { flags_[idx] = v; }
   
   owner_type const & getOwner(const size_t idx) const {return owner_[idx];}
   owner_type& getOwnerRef(const size_t idx) {return owner_[idx];}
   void setOwner(const size_t idx, owner_type const & v) { owner_[idx] = v; }
   
   ghostOwners_type const & getGhostOwners(const size_t idx) const {return ghostOwners_[idx];}
   ghostOwners_type& getGhostOwnersRef(const size_t idx) {return ghostOwners_[idx];}
   void setGhostOwners(const size_t idx, ghostOwners_type const & v) { ghostOwners_[idx] = v; }
   
   velocity_type const & getVelocity(const size_t idx) const {return velocity_[idx];}
   velocity_type& getVelocityRef(const size_t idx) {return velocity_[idx];}
   void setVelocity(const size_t idx, velocity_type const & v) { velocity_[idx] = v; }
   
   currentBlock_type const & getCurrentBlock(const size_t idx) const {return currentBlock_[idx];}
   currentBlock_type& getCurrentBlockRef(const size_t idx) {return currentBlock_[idx];}
   void setCurrentBlock(const size_t idx, currentBlock_type const & v) { currentBlock_[idx] = v; }
   
   neighborState_type const & getNeighborState(const size_t idx) const {return neighborState_[idx];}
   neighborState_type& getNeighborStateRef(const size_t idx) {return neighborState_[idx];}
   void setNeighborState(const size_t idx, neighborState_type const & v) { neighborState_[idx] = v; }
   

   /**
    * @brief creates a new particle and returns an iterator pointing to it
    *
    * \attention Use this function only if you know what you are doing!
    * Messing with the uid might break the simulation!
    * If you are unsure use create(bool) instead.
    * @param uid unique id of the particle to be created
    * @return iterator to the newly created particle
    */
   inline iterator create(const uid_type& uid);
   inline iterator create(const bool global = false);
   inline iterator erase(iterator& it);
   /// Finds the entry corresponding to \p uid.
   /// \return iterator to the object or end iterator
   inline iterator find(const uid_type& uid);
   inline void reserve(const size_t size);
   inline void clear();
   inline size_t size() const;
   template <class Compare>
   void sort(Compare comp);

   /**
    * Calls the provided functor \p func for all Particles.
    *
    * Additional arguments can be provided.
    * Call syntax for the provided functor
    * \code
    * func( *this, i, std::forward<Args>(args)... );
    * \endcode
    * \param openmp enables/disables OpenMP parallelization of the kernel call
    */
   template <typename Selector, typename Accessor, typename Func, typename... Args>
   inline void forEachParticle(const bool openmp,
                               const Selector& selector,
                               Accessor& acForPS,
                               Func&& func,
                               Args&&... args);
   template <typename Selector, typename Accessor, typename Func, typename... Args>
   inline void forEachParticle(const bool openmp,
                               const Selector& selector,
                               Accessor& acForPS,
                               Func&& func,
                               Args&&... args) const;
   /**
    * Calls the provided functor \p func for all Particle pairs.
    *
    * Additional arguments can be provided. No pairs with twice the same Particle.
    * Call syntax for the provided functor
    * \code
    * func( *this, i, j, std::forward<Args>(args)... );
    * \endcode
    * \param openmp enables/disables OpenMP parallelization of the kernel call
    */
   template <typename Selector, typename Accessor, typename Func, typename... Args>
   inline void forEachParticlePair(const bool openmp,
                                   const Selector& selector,
                                   Accessor& acForPS,
                                   Func&& func,
                                   Args&&... args);
   template <typename Selector, typename Accessor, typename Func, typename... Args>
   inline void forEachParticlePair(const bool openmp,
                                   const Selector& selector,
                                   Accessor& acForPS,
                                   Func&& func,
                                   Args&&... args) const;
   /**
    * Calls the provided functor \p func for all Particle pairs.
    *
    * Additional arguments can be provided. No pairs with twice the same Particle.
    * Index of the first particle i will be always smaller than j! No pair is called twice!
    * Call syntax for the provided functor
    * \code
    * func( *this, i, j, std::forward<Args>(args)... );
    * \endcode
    * \param openmp enables/disables OpenMP parallelization of the kernel call
    */
   template <typename Selector, typename Accessor, typename Func, typename... Args>
   inline void forEachParticlePairHalf(const bool openmp,
                                       const Selector& selector,
                                       Accessor& acForPS,
                                       Func&& func,
                                       Args&&... args);
   template <typename Selector, typename Accessor, typename Func, typename... Args>
   inline void forEachParticlePairHalf(const bool openmp,
                                       const Selector& selector,
                                       Accessor& acForPS,
                                       Func&& func,
                                       Args&&... args) const;

   private:
   std::vector<uid_type> uid_ {};
   std::vector<position_type> position_ {};
   std::vector<interactionRadius_type> interactionRadius_ {};
   std::vector<flags_type> flags_ {};
   std::vector<owner_type> owner_ {};
   std::vector<ghostOwners_type> ghostOwners_ {};
   std::vector<velocity_type> velocity_ {};
   std::vector<currentBlock_type> currentBlock_ {};
   std::vector<neighborState_type> neighborState_ {};
   std::unordered_map<uid_type, size_t> uidToIdx_;
   static_assert(std::is_same<uid_type, id_t>::value,
                 "Property uid of type id_t is missing. This property is required!");
};
using Particle = ParticleStorage::Particle;

inline
ParticleStorage::Particle& ParticleStorage::Particle::operator=(const ParticleStorage::Particle& rhs)
{
   getUidRef() = rhs.getUid();
   getPositionRef() = rhs.getPosition();
   getInteractionRadiusRef() = rhs.getInteractionRadius();
   getFlagsRef() = rhs.getFlags();
   getOwnerRef() = rhs.getOwner();
   getGhostOwnersRef() = rhs.getGhostOwners();
   getVelocityRef() = rhs.getVelocity();
   getCurrentBlockRef() = rhs.getCurrentBlock();
   getNeighborStateRef() = rhs.getNeighborState();
   return *this;
}

inline
ParticleStorage::Particle& ParticleStorage::Particle::operator=(ParticleStorage::Particle&& rhs)
{
   getUidRef() = std::move(rhs.getUidRef());
   getPositionRef() = std::move(rhs.getPositionRef());
   getInteractionRadiusRef() = std::move(rhs.getInteractionRadiusRef());
   getFlagsRef() = std::move(rhs.getFlagsRef());
   getOwnerRef() = std::move(rhs.getOwnerRef());
   getGhostOwnersRef() = std::move(rhs.getGhostOwnersRef());
   getVelocityRef() = std::move(rhs.getVelocityRef());
   getCurrentBlockRef() = std::move(rhs.getCurrentBlockRef());
   getNeighborStateRef() = std::move(rhs.getNeighborStateRef());
   return *this;
}

inline
void swap(ParticleStorage::Particle lhs, ParticleStorage::Particle rhs)
{
   if (lhs.i_ == rhs.i_) return;
   std::swap(lhs.getUidRef(), rhs.getUidRef());
   std::swap(lhs.getPositionRef(), rhs.getPositionRef());
   std::swap(lhs.getInteractionRadiusRef(), rhs.getInteractionRadiusRef());
   std::swap(lhs.getFlagsRef(), rhs.getFlagsRef());
   std::swap(lhs.getOwnerRef(), rhs.getOwnerRef());
   std::swap(lhs.getGhostOwnersRef(), rhs.getGhostOwnersRef());
   std::swap(lhs.getVelocityRef(), rhs.getVelocityRef());
   std::swap(lhs.getCurrentBlockRef(), rhs.getCurrentBlockRef());
   std::swap(lhs.getNeighborStateRef(), rhs.getNeighborStateRef());
}

inline
std::ostream& operator<<( std::ostream& os, const ParticleStorage::Particle& p )
{
   os << "==========    ==========" << "\n" <<
         "idx                 : " << p.getIdx() << "\n" <<
         "uid                 : " << p.getUid() << "\n" <<
         "position            : " << p.getPosition() << "\n" <<
         "interactionRadius   : " << p.getInteractionRadius() << "\n" <<
         "flags               : " << p.getFlags() << "\n" <<
         "owner               : " << p.getOwner() << "\n" <<
         "ghostOwners         : " << p.getGhostOwners() << "\n" <<
         "velocity            : " << p.getVelocity() << "\n" <<
         "currentBlock        : " << p.getCurrentBlock() << "\n" <<
         "neighborState       : " << p.getNeighborState() << "\n" <<
         "================================" << std::endl;
   return os;
}

inline
ParticleStorage::iterator operator+(const ParticleStorage::iterator& it, const size_t n)
{
   return ParticleStorage::iterator(it.storage_, it.i_+n);
}

inline
ParticleStorage::iterator operator+(const size_t n, const ParticleStorage::iterator& it)
{
   return it + n;
}

inline
ParticleStorage::iterator operator-(const ParticleStorage::iterator& it, const size_t n)
{
   return ParticleStorage::iterator(it.storage_, it.i_-n);
}

inline
ParticleStorage::iterator::difference_type operator-(const ParticleStorage::iterator& lhs, const ParticleStorage::iterator& rhs)
{
   return int64_c(lhs.i_) - int64_c(rhs.i_);
}

inline bool operator==(const ParticleStorage::iterator& lhs, const ParticleStorage::iterator& rhs)
{
   WALBERLA_ASSERT_EQUAL(lhs.storage_, rhs.storage_);
   return (lhs.i_ == rhs.i_);
}
inline bool operator!=(const ParticleStorage::iterator& lhs, const ParticleStorage::iterator& rhs)
{
   WALBERLA_ASSERT_EQUAL(lhs.storage_, rhs.storage_);
   return (lhs.i_ != rhs.i_);
}
inline bool operator<(const ParticleStorage::iterator& lhs, const ParticleStorage::iterator& rhs)
{
   WALBERLA_ASSERT_EQUAL(lhs.storage_, rhs.storage_);
   return (lhs.i_ < rhs.i_);
}
inline bool operator>(const ParticleStorage::iterator& lhs, const ParticleStorage::iterator& rhs)
{
   WALBERLA_ASSERT_EQUAL(lhs.storage_, rhs.storage_);
   return (lhs.i_ > rhs.i_);
}
inline bool operator<=(const ParticleStorage::iterator& lhs, const ParticleStorage::iterator& rhs)
{
   WALBERLA_ASSERT_EQUAL(lhs.storage_, rhs.storage_);
   return (lhs.i_ <= rhs.i_);
}
inline bool operator>=(const ParticleStorage::iterator& lhs, const ParticleStorage::iterator& rhs)
{
   WALBERLA_ASSERT_EQUAL(lhs.storage_, rhs.storage_);
   return (lhs.i_ >= rhs.i_);
}

inline void swap(ParticleStorage::iterator& lhs, ParticleStorage::iterator& rhs)
{
   WALBERLA_ASSERT_EQUAL(lhs.storage_, rhs.storage_);
   std::swap(lhs.i_, rhs.i_);
}

inline
ParticleStorage::ParticleStorage(const size_t size)
{
   reserve(size);
}


inline ParticleStorage::iterator ParticleStorage::create(const id_t& uid)
{
   WALBERLA_ASSERT_EQUAL(uidToIdx_.find(uid),
                         uidToIdx_.end(),
                         "particle with the same uid(" << uid <<") already existing at index(" << uidToIdx_.find(uid)->second << ")");
   uid_.emplace_back(UniqueID<data::Particle>::invalidID());
   position_.emplace_back(real_t(0));
   interactionRadius_.emplace_back(real_t(0));
   flags_.emplace_back();
   owner_.emplace_back(-1);
   ghostOwners_.emplace_back();
   velocity_.emplace_back(real_t(0));
   currentBlock_.emplace_back();
   neighborState_.emplace_back();
   uid_.back() = uid;
   uidToIdx_[uid] = uid_.size() - 1;
   return iterator(this, size() - 1);
}

inline ParticleStorage::iterator ParticleStorage::create(const bool global)
{
   if (global)
   {
      auto it = create(UniqueID<Particle>::createGlobal());
      data::particle_flags::set(flags_.back(), data::particle_flags::GLOBAL);
      data::particle_flags::set(flags_.back(), data::particle_flags::NON_COMMUNICATING);
      return it;
   } else
   {
      return create(UniqueID<Particle>::create());
   }
}

inline ParticleStorage::iterator ParticleStorage::erase(iterator& it)
{
   //swap with last element and pop
   auto last = --end();
   auto numElementsRemoved = uidToIdx_.erase(it->getUid());
   WALBERLA_CHECK_EQUAL(numElementsRemoved,
                        1,
                        "Particle with uid " << it->getUid() << " cannot be removed (not existing).");
   if (it != last) //skip swap if last element is removed
   {
      *it = *last;
      uidToIdx_[it->getUid()] = it.getIdx();
   }
   uid_.pop_back();
   position_.pop_back();
   interactionRadius_.pop_back();
   flags_.pop_back();
   owner_.pop_back();
   ghostOwners_.pop_back();
   velocity_.pop_back();
   currentBlock_.pop_back();
   neighborState_.pop_back();
   return it;
}

inline ParticleStorage::iterator ParticleStorage::find(const id_t& uid)
{
   //linear search through uid vector
   //auto it = std::find(uid_.begin(), uid_.end(), uid);
   //if (it == uid_.end()) return end();
   //return iterator(this, uint_c(std::distance(uid_.begin(), it)));

   //use unordered_map for faster lookup
   auto it = uidToIdx_.find(uid);
   if (it == uidToIdx_.end()) return end();
   WALBERLA_ASSERT_EQUAL(getUid(it->second), uid, "Lookup via uidToIdx map is not up to date!!!");
   return iterator(this, it->second);
}

inline void ParticleStorage::reserve(const size_t size)
{
   uid_.reserve(size);
   position_.reserve(size);
   interactionRadius_.reserve(size);
   flags_.reserve(size);
   owner_.reserve(size);
   ghostOwners_.reserve(size);
   velocity_.reserve(size);
   currentBlock_.reserve(size);
   neighborState_.reserve(size);
}

inline void ParticleStorage::clear()
{
   uid_.clear();
   position_.clear();
   interactionRadius_.clear();
   flags_.clear();
   owner_.clear();
   ghostOwners_.clear();
   velocity_.clear();
   currentBlock_.clear();
   neighborState_.clear();
   uidToIdx_.clear();
}

inline size_t ParticleStorage::size() const
{
   //WALBERLA_ASSERT_EQUAL( uid_.size(), uid.size() );
   //WALBERLA_ASSERT_EQUAL( uid_.size(), position.size() );
   //WALBERLA_ASSERT_EQUAL( uid_.size(), interactionRadius.size() );
   //WALBERLA_ASSERT_EQUAL( uid_.size(), flags.size() );
   //WALBERLA_ASSERT_EQUAL( uid_.size(), owner.size() );
   //WALBERLA_ASSERT_EQUAL( uid_.size(), ghostOwners.size() );
   //WALBERLA_ASSERT_EQUAL( uid_.size(), velocity.size() );
   //WALBERLA_ASSERT_EQUAL( uid_.size(), currentBlock.size() );
   //WALBERLA_ASSERT_EQUAL( uid_.size(), neighborState.size() );
   return uid_.size();
}

template <class Compare>
void ParticleStorage::sort(Compare comp)
{
   using WeightPair = std::pair<size_t, double>; //idx, weight

   const size_t length = size();
   std::vector<size_t>     newIdx(length); //where is old idx now?
   std::vector<size_t>     oldIdx(length); //what old idx is at that idx?
   std::vector<WeightPair> weight(length);

   for (size_t idx = 0; idx < length; ++idx)
   {
      newIdx[idx] = idx;
      oldIdx[idx] = idx;
      weight[idx] = std::make_pair(idx, comp.getWeight(operator[](idx)));
   }
   std::sort(weight.begin(), weight.end(), [](const WeightPair& lhs, const WeightPair& rhs){return lhs.second < rhs.second;});
   for (size_t idx = 0; idx < length; ++idx)
   {
      using std::swap;
      WALBERLA_ASSERT_IDENTICAL(weight[idx].second, comp.getWeight(operator[](newIdx[weight[idx].first])));

      WALBERLA_ASSERT_LESS_EQUAL(comp.getWeight(operator[](newIdx[weight[idx].first])), comp.getWeight(operator[](idx)));
      swap( operator[](idx), operator[](newIdx[weight[idx].first]) );
      const auto lhsIDX = idx;
      const auto rhsIDX = newIdx[weight[idx].first];

      newIdx[oldIdx[lhsIDX]] = rhsIDX;
      newIdx[oldIdx[rhsIDX]] = lhsIDX;

      swap(oldIdx[lhsIDX], oldIdx[rhsIDX]);
   }

   //rebuild lookup table
   uidToIdx_.clear();
   for (size_t idx = 0; idx < length; ++idx)
   {
      uidToIdx_[getUid(idx)] = idx;
   }
}
template <typename Selector, typename Accessor, typename Func, typename... Args>
inline void ParticleStorage::forEachParticle(const bool openmp,
                                             const Selector& selector,
                                             Accessor& acForPS,
                                             Func&& func, Args&&... args) 
{
   static_assert (std::is_base_of<data::IAccessor, Accessor>::value, "please provide a valid accessor" );

   WALBERLA_UNUSED(openmp);
   const uint64_t len = size();
   #ifdef _OPENMP
   #pragma omp parallel for schedule(static) if (openmp)
   #endif
   for (int64_t i = 0; i < int64_c(len); ++i)
   {
      if (selector(uint64_c(i), acForPS))
         func( uint64_c(i), std::forward<Args>(args)... );
   }
}
template <typename Selector, typename Accessor, typename Func, typename... Args>
inline void ParticleStorage::forEachParticle(const bool openmp,
                                             const Selector& selector,
                                             Accessor& acForPS,
                                             Func&& func, Args&&... args) const
{
   static_assert (std::is_base_of<data::IAccessor, Accessor>::value, "please provide a valid accessor" );

   WALBERLA_UNUSED(openmp);
   const uint64_t len = size();
   #ifdef _OPENMP
   #pragma omp parallel for schedule(static) if (openmp)
   #endif
   for (int64_t i = 0; i < int64_c(len); ++i)
   {
      if (selector(uint64_c(i), acForPS))
         func( uint64_c(i), std::forward<Args>(args)... );
   }
}
template <typename Selector, typename Accessor, typename Func, typename... Args>
inline void ParticleStorage::forEachParticlePair(const bool openmp,
                                                 const Selector& selector,
                                                 Accessor& acForPS,
                                                 Func&& func, Args&&... args) 
{
   static_assert (std::is_base_of<data::IAccessor, Accessor>::value, "please provide a valid accessor" );

   WALBERLA_UNUSED(openmp);
   const uint64_t len = size();
   #ifdef _OPENMP
   #pragma omp parallel for schedule(static) if (openmp)
   #endif
   for (int64_t i = 0; i < int64_c(len); ++i)
   {
      for (int64_t j = 0; j < int64_c(len); ++j)
      {
         if (i!=j)
         {
            if (selector(uint64_c(i), uint64_c(j), acForPS))
            {
               func( uint64_c(i), uint64_c(j), std::forward<Args>(args)... );
            }
         }
      }
   }
}
template <typename Selector, typename Accessor, typename Func, typename... Args>
inline void ParticleStorage::forEachParticlePair(const bool openmp,
                                                 const Selector& selector,
                                                 Accessor& acForPS,
                                                 Func&& func, Args&&... args) const
{
   static_assert (std::is_base_of<data::IAccessor, Accessor>::value, "please provide a valid accessor" );

   WALBERLA_UNUSED(openmp);
   const uint64_t len = size();
   #ifdef _OPENMP
   #pragma omp parallel for schedule(static) if (openmp)
   #endif
   for (int64_t i = 0; i < int64_c(len); ++i)
   {
      for (int64_t j = 0; j < int64_c(len); ++j)
      {
         if (i!=j)
         {
            if (selector(uint64_c(i), uint64_c(j), acForPS))
            {
               func( uint64_c(i), uint64_c(j), std::forward<Args>(args)... );
            }
         }
      }
   }
}
template <typename Selector, typename Accessor, typename Func, typename... Args>
inline void ParticleStorage::forEachParticlePairHalf(const bool openmp,
                                                     const Selector& selector,
                                                     Accessor& acForPS,
                                                     Func&& func, Args&&... args) 
{
   static_assert (std::is_base_of<data::IAccessor, Accessor>::value, "please provide a valid accessor" );

   WALBERLA_UNUSED(openmp);
   const uint64_t len = size();
   #ifdef _OPENMP
   #pragma omp parallel for schedule(static) if (openmp)
   #endif
   for (int64_t i = 0; i < int64_c(len); ++i)
   {
      for (int64_t j = i+1; j < int64_c(len); ++j)
      {
         if (selector(uint64_c(i), uint64_c(j), acForPS))
         {
            func( uint64_c(i), uint64_c(j), std::forward<Args>(args)... );
         }
      }
   }
}
template <typename Selector, typename Accessor, typename Func, typename... Args>
inline void ParticleStorage::forEachParticlePairHalf(const bool openmp,
                                                     const Selector& selector,
                                                     Accessor& acForPS,
                                                     Func&& func, Args&&... args) const
{
   static_assert (std::is_base_of<data::IAccessor, Accessor>::value, "please provide a valid accessor" );

   WALBERLA_UNUSED(openmp);
   const uint64_t len = size();
   #ifdef _OPENMP
   #pragma omp parallel for schedule(static) if (openmp)
   #endif
   for (int64_t i = 0; i < int64_c(len); ++i)
   {
      for (int64_t j = i+1; j < int64_c(len); ++j)
      {
         if (selector(uint64_c(i), uint64_c(j), acForPS))
         {
            func( uint64_c(i), uint64_c(j), std::forward<Args>(args)... );
         }
      }
   }
}
///Predicate that selects a certain property from a Particle
class SelectParticleUid
{
public:
   using return_type = walberla::id_t;
   walberla::id_t& operator()(data::Particle& p) const {return p.getUidRef();}
   walberla::id_t& operator()(data::Particle&& p) const {return p.getUidRef();}
   walberla::id_t const & operator()(const data::Particle& p) const {return p.getUid();}
};
///Predicate that selects a certain property from a Particle
class SelectParticlePosition
{
public:
   using return_type = walberla::convection_particles::Vec3;
   walberla::convection_particles::Vec3& operator()(data::Particle& p) const {return p.getPositionRef();}
   walberla::convection_particles::Vec3& operator()(data::Particle&& p) const {return p.getPositionRef();}
   walberla::convection_particles::Vec3 const & operator()(const data::Particle& p) const {return p.getPosition();}
};
///Predicate that selects a certain property from a Particle
class SelectParticleInteractionRadius
{
public:
   using return_type = walberla::real_t;
   walberla::real_t& operator()(data::Particle& p) const {return p.getInteractionRadiusRef();}
   walberla::real_t& operator()(data::Particle&& p) const {return p.getInteractionRadiusRef();}
   walberla::real_t const & operator()(const data::Particle& p) const {return p.getInteractionRadius();}
};
///Predicate that selects a certain property from a Particle
class SelectParticleFlags
{
public:
   using return_type = walberla::convection_particles::data::particle_flags::FlagT;
   walberla::convection_particles::data::particle_flags::FlagT& operator()(data::Particle& p) const {return p.getFlagsRef();}
   walberla::convection_particles::data::particle_flags::FlagT& operator()(data::Particle&& p) const {return p.getFlagsRef();}
   walberla::convection_particles::data::particle_flags::FlagT const & operator()(const data::Particle& p) const {return p.getFlags();}
};
///Predicate that selects a certain property from a Particle
class SelectParticleOwner
{
public:
   using return_type = int;
   int& operator()(data::Particle& p) const {return p.getOwnerRef();}
   int& operator()(data::Particle&& p) const {return p.getOwnerRef();}
   int const & operator()(const data::Particle& p) const {return p.getOwner();}
};
///Predicate that selects a certain property from a Particle
class SelectParticleGhostOwners
{
public:
   using return_type = std::unordered_set<walberla::mpi::MPIRank>;
   std::unordered_set<walberla::mpi::MPIRank>& operator()(data::Particle& p) const {return p.getGhostOwnersRef();}
   std::unordered_set<walberla::mpi::MPIRank>& operator()(data::Particle&& p) const {return p.getGhostOwnersRef();}
   std::unordered_set<walberla::mpi::MPIRank> const & operator()(const data::Particle& p) const {return p.getGhostOwners();}
};
///Predicate that selects a certain property from a Particle
class SelectParticleVelocity
{
public:
   using return_type = walberla::convection_particles::Vec3;
   walberla::convection_particles::Vec3& operator()(data::Particle& p) const {return p.getVelocityRef();}
   walberla::convection_particles::Vec3& operator()(data::Particle&& p) const {return p.getVelocityRef();}
   walberla::convection_particles::Vec3 const & operator()(const data::Particle& p) const {return p.getVelocity();}
};
///Predicate that selects a certain property from a Particle
class SelectParticleCurrentBlock
{
public:
   using return_type = blockforest::BlockID;
   blockforest::BlockID& operator()(data::Particle& p) const {return p.getCurrentBlockRef();}
   blockforest::BlockID& operator()(data::Particle&& p) const {return p.getCurrentBlockRef();}
   blockforest::BlockID const & operator()(const data::Particle& p) const {return p.getCurrentBlock();}
};
///Predicate that selects a certain property from a Particle
class SelectParticleNeighborState
{
public:
   using return_type = std::unordered_set<walberla::mpi::MPIRank>;
   std::unordered_set<walberla::mpi::MPIRank>& operator()(data::Particle& p) const {return p.getNeighborStateRef();}
   std::unordered_set<walberla::mpi::MPIRank>& operator()(data::Particle&& p) const {return p.getNeighborStateRef();}
   std::unordered_set<walberla::mpi::MPIRank> const & operator()(const data::Particle& p) const {return p.getNeighborState();}
};

} //namespace data
} //namespace convection_particles
} //namespace walberla