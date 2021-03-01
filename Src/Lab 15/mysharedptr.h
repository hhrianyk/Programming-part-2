#pragma once
#include <atomic> // atomic_long
#include <utility> // swap, forward
#include <type_traits> // add_lvalue_reference
namespace my {
	template<class T> class shared_ptr {
	private:
		typedef std::atomic_long counter_type;

		counter_type *m_refs;
		T *m_ptr;

		void add_ref() {
			if (m_refs)
				++*m_refs;
		}
		void release_ref() {
			if (m_refs && --*m_refs == 0) {
				delete m_ptr;
				m_ptr = nullptr;
				delete m_refs;
				m_refs = nullptr;
			}
		}

	public:
		typedef T element_type;

		// constructors
		constexpr shared_ptr() noexcept :m_refs(nullptr), m_ptr(nullptr) {}
		explicit shared_ptr(T *p) :m_refs(new counter_type(1)), m_ptr(p) {}
		shared_ptr(const shared_ptr &r) noexcept : m_refs(r.m_refs), m_ptr(r.m_ptr) {
			add_ref();
		}
		shared_ptr(shared_ptr &&r) noexcept : m_refs(nullptr), m_ptr(nullptr) {
			swap(r);
		}

		// destructor
		~shared_ptr() {
			release_ref();
		}

		// assignment
		shared_ptr &operator=(const shared_ptr &r) noexcept {
			if (this == &r)
				return *this;
			release_ref();
			m_refs = r.m_refs;
			m_ptr = r.m_ptr;
			add_ref();
			return *this;
		}
		shared_ptr &operator=(shared_ptr &&r) noexcept {
			swap(r);
			return *this;
		}

		// modifiers
		void swap(shared_ptr &r) noexcept {
			using std::swap;
			swap(m_refs, r.m_refs);
			swap(m_ptr, r.m_ptr);
		}
		void reset() noexcept {
			shared_ptr().swap(*this);
		}
		void reset(T *p) noexcept {
			shared_ptr(p).swap(*this);
		}

		// observers
		T *get() const noexcept {
			return m_ptr;
		}
		// NOTE: (typename std::add_lvalue_reference<T>::type => T&) doesn't work for T=void 
		typename std::add_lvalue_reference<T>::type operator*() const noexcept {
			return *m_ptr;
		}
		T *operator->() const noexcept {
			return m_ptr;
		}
		long use_count() const noexcept {
			return m_refs ? long(*m_refs) : 0;
		}
		explicit operator bool() const noexcept {
			return m_ptr != 0;
		}
	};
	template<class T> inline void swap(shared_ptr<T> &lhs, shared_ptr<T> &rhs) {
		lhs.swap(rhs);
	}
	template<class T, class... Args> inline shared_ptr<T> make_shared(Args&&... args) {
		return shared_ptr<T>(new T(std::forward<Args>(args)...));
	}
	template<class T> inline bool operator==(const shared_ptr<T> &lhs, const shared_ptr<T> &rhs) {
		return lhs.get() == rhs.get();
	}
}
