#pragma once
#include <atomic> // atomic_long
#include <utility> // swap, forward
#include <type_traits> // add_lvalue_reference
namespace my {
	template<class T> class UNO {
	private:
		typedef std::atomic_long counter_type;

		counter_type* m_refs;//лічільник
		T* m_ptr;//вказівник

		void add_ref() {//лічильник++цвщоаащащ33030аао30ао30к303кша3кшк3ш
			if (m_refs)
				++* m_refs;
		}
		void release_ref() {//знищення вказіввника про 0
			if (m_refs && -- * m_refs == 0) {
				delete m_ptr;
				m_ptr = nullptr;
				delete m_refs;
				m_refs = nullptr;
			}
		}

	public:
		typedef T element_type;

		// constructors
		constexpr UNO() noexcept :m_refs(nullptr), m_ptr(nullptr) {}
		explicit UNO(T* p) :m_refs(new counter_type(1)), m_ptr(p) {}
		UNO(const UNO& r) noexcept : m_refs(r.m_refs), m_ptr(r.m_ptr) {
			add_ref();
		}
		UNO(UNO&& r) noexcept : m_refs(nullptr), m_ptr(nullptr) {
			swap(r);
		}

		// destructor
		~UNO() {
			release_ref();
		}

		// assignment
		UNO& operator=(const UNO& r) noexcept {
			if (this == &r)
				return *this;
			release_ref();
			m_refs = r.m_refs;
			m_ptr = r.m_ptr;
			add_ref();
			return *this;
		}
		UNO& operator=(UNO&& r) noexcept {
			swap(r);
			return *this;
		}

		// modifiers
		void swap(UNO& r) noexcept {
			using std::swap;
			swap(m_refs, r.m_refs);
			swap(m_ptr, r.m_ptr);
		}
		void reset() noexcept {
			UNO().swap(*this);
		}
		void reset(T* p) noexcept {
			UNO(p).swap(*this);
		}

		// observers
		T* get() const noexcept {
			return m_ptr;
		}
		// NOTE: (typename std::add_lvalue_reference<T>::type => T&) doesn't work for T=void 
		typename std::add_lvalue_reference<T>::type operator*() const noexcept {
			return *m_ptr;
		}
		T* operator->() const noexcept {
			return m_ptr;
		}
		long use_count() const noexcept {
			return m_refs ? long(*m_refs) : 0;
		}
		explicit operator bool() const noexcept {
			return m_ptr != 0;
		}
	};
	template<class T> inline void swap(UNO<T>& lhs, UNO<T>& rhs) {
		lhs.swap(rhs);
	}
	template<class T, class... Args> inline UNO<T> make(Args&&... args) {
		return UNO<T>(new T(std::forward<Args>(args)...));
	}
	template<class T> inline bool operator==(const UNO<T>& lhs, const UNO<T>& rhs) {
		return lhs.get() == rhs.get();
	}
}
 