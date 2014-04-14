#ifndef ObjexxFCL_MArray4_hh_INCLUDED
#define ObjexxFCL_MArray4_hh_INCLUDED

// MArray4: 4D Member Array Proxy
//
// Project: Objexx Fortran Compatibility Library (ObjexxFCL)
//
// Version: 4.0.0
//
// Language: C++
//
// Copyright (c) 2000-2014 Objexx Engineering, Inc. All Rights Reserved.
// Use of this source code or any derivative of it is restricted by license.
// Licensing is available from Objexx Engineering, Inc.:  http://objexx.com

// ObjexxFCL Headers
#include <ObjexxFCL/MArrayR.hh>

namespace ObjexxFCL {

// MArray4: 4D Member Array Proxy
template< class A, typename T >
class MArray4 : public MArrayR< A, T, 4 >
{

private: // Types

	typedef  MArrayR< A, T, 4 >  Super;

private: // Friend

	template< typename, typename > friend class MArray4;

public: // Types

	typedef  typename Super::Array  Array;
	typedef  typename Super::Class  Class;
	typedef  typename Super::MPtr  MPtr;
	typedef  typename Super::Traits  Traits;
	typedef  typename Super::IR  IR;

	// STL Style
	typedef  typename Super::value_type  value_type;
	typedef  typename Super::reference  reference;
	typedef  typename Super::const_reference  const_reference;
	typedef  typename Super::pointer  pointer;
	typedef  typename Super::const_pointer  const_pointer;
	typedef  typename Super::size_type  size_type;
	typedef  typename Super::difference_type  difference_type;

	// C++ Style
	typedef  typename Super::Value  Value;
	typedef  typename Super::Reference  Reference;
	typedef  typename Super::ConstReference  ConstReference;
	typedef  typename Super::Pointer  Pointer;
	typedef  typename Super::ConstPointer  ConstPointer;
	typedef  typename Super::Size  Size;
	typedef  typename Super::Difference  Difference;

	// Using
	using Super::in_range;
	using Super::l;
	using Super::u;
	using Super::size;
	using Super::j1;
	using Super::j2;
	using Super::j3;
	using Super::j4;
	using Super::array_;
	using Super::pmem_;

public: // Creation

	// Copy Constructor
	inline
	MArray4( MArray4 const & a ) :
		Super( a )
	{}

	// Constructor
	inline
	MArray4( A & a, T Class::* pmem ) :
		Super( a, pmem )
	{}

	// Destructor
	inline
	virtual
	~MArray4()
	{}

public: // Assignment

	// Copy Assignment
	inline
	MArray4 &
	operator =( MArray4 const & a )
	{
		if ( this != &a ) {
			assert( conformable( a ) );
			for ( int i4 = 1, e4 = u4(); i4 <= e4; ++i4 ) {
				for ( int i3 = 1, e3 = u3(); i3 <= e3; ++i3 ) {
					for ( int i2 = 1, e2 = u2(); i2 <= e2; ++i2 ) {
						for ( int i1 = 1, e1 = u1(); i1 <= e1; ++i1 ) {
							operator()( i1, i2, i3, i4 ) = a( i1, i2, i3, i4 ); // Not overlap-safe
						}
					}
				}
			}
		}
		return *this;
	}

	// Copy Assignment Template
	template< typename Aa, typename Ta >
	inline
	MArray4 &
	operator =( MArray4< Aa, Ta > const & a )
	{
		assert( conformable( a ) );
		for ( int i4 = 1, e4 = u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = u1(); i1 <= e1; ++i1 ) {
						operator()( i1, i2, i3, i4 ) = a( i1, i2, i3, i4 ); // Not overlap-safe
					}
				}
			}
		}
		return *this;
	}

	// Array Assignment Template
	template< template< typename > class ArrayType, typename U >
	inline
	MArray4 &
	operator =( ArrayType< U > const & a )
	{
		assert( conformable( a ) );
		for ( int i4 = 1, j4 = a.l4(), e4 = u4(); i4 <= e4; ++i4, ++j4 ) {
			for ( int i3 = 1, j3 = a.l3(), e3 = u3(); i3 <= e3; ++i3, ++j3 ) {
				for ( int i2 = 1, j2 = a.l2(), e2 = u2(); i2 <= e2; ++i2, ++j2 ) {
					for ( int i1 = 1, j1 = a.l1(), e1 = u1(); i1 <= e1; ++i1, ++j1 ) {
						operator()( i1, i2, i3, i4 ) = a( j1, j2, j3, j4 ); // Not overlap-safe
					}
				}
			}
		}
		return *this;
	}

	// += MArray4 Template
	template< typename Aa, typename Ta >
	inline
	MArray4 &
	operator +=( MArray4< Aa, Ta > const & a )
	{
		assert( conformable( a ) );
		for ( int i4 = 1, e4 = u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = u1(); i1 <= e1; ++i1 ) {
						operator()( i1, i2, i3, i4 ) += a( i1, i2, i3, i4 ); // Not overlap-safe
					}
				}
			}
		}
		return *this;
	}

	// -= MArray4 Template
	template< typename Aa, typename Ta >
	inline
	MArray4 &
	operator -=( MArray4< Aa, Ta > const & a )
	{
		assert( conformable( a ) );
		for ( int i4 = 1, e4 = u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = u1(); i1 <= e1; ++i1 ) {
						operator()( i1, i2, i3, i4 ) -= a( i1, i2, i3, i4 ); // Not overlap-safe
					}
				}
			}
		}
		return *this;
	}

	// *= MArray4 Template
	template< typename Aa, typename Ta >
	inline
	MArray4 &
	operator *=( MArray4< Aa, Ta > const & a )
	{
		assert( conformable( a ) );
		for ( int i4 = 1, e4 = u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = u1(); i1 <= e1; ++i1 ) {
						operator()( i1, i2, i3, i4 ) *= a( i1, i2, i3, i4 ); // Not overlap-safe
					}
				}
			}
		}
		return *this;
	}

	// /= MArray4 Template
	template< typename Aa, typename Ta >
	inline
	MArray4 &
	operator /=( MArray4< Aa, Ta > const & a )
	{
		assert( conformable( a ) );
		for ( int i4 = 1, e4 = u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = u1(); i1 <= e1; ++i1 ) {
						assert( a( i1, i2, i3, i4 ) != T( 0 ) );
						operator()( i1, i2, i3, i4 ) /= a( i1, i2, i3, i4 ); // Not overlap-safe
					}
				}
			}
		}
		return *this;
	}

	// += Array Template
	template< template< typename > class ArrayType, typename U >
	inline
	MArray4 &
	operator +=( ArrayType< U > const & a )
	{
		assert( conformable( a ) );
		for ( int i4 = 1, j4 = a.l4(), e4 = u4(); i4 <= e4; ++i4, ++j4 ) {
			for ( int i3 = 1, j3 = a.l3(), e3 = u3(); i3 <= e3; ++i3, ++j3 ) {
				for ( int i2 = 1, j2 = a.l2(), e2 = u2(); i2 <= e2; ++i2, ++j2 ) {
					for ( int i1 = 1, j1 = a.l1(), e1 = u1(); i1 <= e1; ++i1, ++j1 ) {
						operator()( i1, i2, i3, i4 ) += a( j1, j2, j3, j4 ); // Not overlap-safe
					}
				}
			}
		}
		return *this;
	}

	// -= Array Template
	template< template< typename > class ArrayType, typename U >
	inline
	MArray4 &
	operator -=( ArrayType< U > const & a )
	{
		assert( conformable( a ) );
		for ( int i4 = 1, j4 = a.l4(), e4 = u4(); i4 <= e4; ++i4, ++j4 ) {
			for ( int i3 = 1, j3 = a.l3(), e3 = u3(); i3 <= e3; ++i3, ++j3 ) {
				for ( int i2 = 1, j2 = a.l2(), e2 = u2(); i2 <= e2; ++i2, ++j2 ) {
					for ( int i1 = 1, j1 = a.l1(), e1 = u1(); i1 <= e1; ++i1, ++j1 ) {
						operator()( i1, i2, i3, i4 ) -= a( j1, j2, j3, j4 ); // Not overlap-safe
					}
				}
			}
		}
		return *this;
	}

	// *= Array Template
	template< template< typename > class ArrayType, typename U >
	inline
	MArray4 &
	operator *=( ArrayType< U > const & a )
	{
		assert( conformable( a ) );
		for ( int i4 = 1, j4 = a.l4(), e4 = u4(); i4 <= e4; ++i4, ++j4 ) {
			for ( int i3 = 1, j3 = a.l3(), e3 = u3(); i3 <= e3; ++i3, ++j3 ) {
				for ( int i2 = 1, j2 = a.l2(), e2 = u2(); i2 <= e2; ++i2, ++j2 ) {
					for ( int i1 = 1, j1 = a.l1(), e1 = u1(); i1 <= e1; ++i1, ++j1 ) {
						operator()( i1, i2, i3, i4 ) *= a( j1, j2, j3, j4 ); // Not overlap-safe
					}
				}
			}
		}
		return *this;
	}

	// /= Array Template
	template< template< typename > class ArrayType, typename U >
	inline
	MArray4 &
	operator /=( ArrayType< U > const & a )
	{
		assert( conformable( a ) );
		for ( int i4 = 1, j4 = a.l4(), e4 = u4(); i4 <= e4; ++i4, ++j4 ) {
			for ( int i3 = 1, j3 = a.l3(), e3 = u3(); i3 <= e3; ++i3, ++j3 ) {
				for ( int i2 = 1, j2 = a.l2(), e2 = u2(); i2 <= e2; ++i2, ++j2 ) {
					for ( int i1 = 1, j1 = a.l1(), e1 = u1(); i1 <= e1; ++i1, ++j1 ) {
						assert( a( j1, j2, j3, j4 ) != T( 0 ) );
						operator()( i1, i2, i3, i4 ) /= a( j1, j2, j3, j4 ); // Not overlap-safe
					}
				}
			}
		}
		return *this;
	}

	// = Value
	inline
	MArray4 &
	operator =( T const & t )
	{
		for ( int i4 = 1, e4 = u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = u1(); i1 <= e1; ++i1 ) {
						operator()( i1, i2, i3, i4 ) = t;
					}
				}
			}
		}
		return *this;
	}

	// = Value Template
	template< typename U >
	inline
	MArray4 &
	operator =( U const & t )
	{
		for ( int i4 = 1, e4 = u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = u1(); i1 <= e1; ++i1 ) {
						operator()( i1, i2, i3, i4 ) = t;
					}
				}
			}
		}
		return *this;
	}

	// += Value
	inline
	MArray4 &
	operator +=( T const & t )
	{
		for ( int i4 = 1, e4 = u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = u1(); i1 <= e1; ++i1 ) {
						operator()( i1, i2, i3, i4 ) += t;
					}
				}
			}
		}
		return *this;
	}

	// -= Value
	inline
	MArray4 &
	operator -=( T const & t )
	{
		for ( int i4 = 1, e4 = u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = u1(); i1 <= e1; ++i1 ) {
						operator()( i1, i2, i3, i4 ) -= t;
					}
				}
			}
		}
		return *this;
	}

	// *= Value
	inline
	MArray4 &
	operator *=( T const & t )
	{
		for ( int i4 = 1, e4 = u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = u1(); i1 <= e1; ++i1 ) {
						operator()( i1, i2, i3, i4 ) *= t;
					}
				}
			}
		}
		return *this;
	}

	// /= Value
	inline
	MArray4 &
	operator /=( T const & t )
	{
		assert( t != T( 0 ) );
		for ( int i4 = 1, e4 = u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = u1(); i1 <= e1; ++i1 ) {
						operator()( i1, i2, i3, i4 ) /= t;
					}
				}
			}
		}
		return *this;
	}

public: // Subscript

	// array( i1, i2, i3, i4 ) const
	inline
	T const &
	operator ()( int const i1, int const i2, int const i3, int const i4 ) const
	{
		assert( contains( i1, i2, i3, i4 ) );
		return array_( j1( i1 ), j2( i2 ), j2( i3 ), j2( i4 ) ).*pmem_;
	}

	// array( i1, i2, i3, i4 )
	inline
	T &
	operator ()( int const i1, int const i2, int const i3, int const i4 )
	{
		assert( contains( i1, i2, i3, i4 ) );
		return array_( j1( i1 ), j2( i2 ), j2( i3 ), j2( i4 ) ).*pmem_;
	}

public: // Predicate

	// contains( i1, i2, i3, i4 )
	inline
	bool
	contains( int const i1, int const i2, int const i3, int const i4 ) const
	{
		if ( ! in_range( u1(), i1 ) ) return false;
		if ( ! in_range( u2(), i2 ) ) return false;
		if ( ! in_range( u3(), i3 ) ) return false;
		if ( ! in_range( u4(), i4 ) ) return false;
		return true;
	}

	// Conformable?
	template< typename Aa, typename Ta >
	inline
	bool
	conformable( MArray4< Aa, Ta > const & a ) const
	{
		return ( ( size1() == a.size1() ) && ( size2() == a.size2() ) && ( size3() == a.size3() ) && ( size4() == a.size4() ) );
	}

	// Conformable?
	template< class ArrayType >
	inline
	bool
	conformable( ArrayType const & a ) const
	{
		return ( ( a.rank() == 4 ) && ( size1() == a.size1() ) && ( size2() == a.size2() ) && ( size3() == a.size3() ) && ( size4() == a.size4() ) );
	}

	// Equal Dimensions?
	template< typename Aa, typename Ta >
	inline
	bool
	equal_dimensions( MArray4< Aa, Ta > const & a ) const
	{
		return conformable( a );
	}

	// Equal Dimensions?
	template< class ArrayType >
	inline
	bool
	equal_dimensions( ArrayType const & a ) const
	{
		return conformable( a );
	}

public: // Inspector

	// IndexRange of Dimension 1
	inline
	IR
	I1() const
	{
		return IR( 1, u1() );
	}

	// Lower Index of Dimension 1
	inline
	int
	l1() const
	{
		return 1;
	}

	// Upper Index of Dimension 1
	inline
	int
	u1() const
	{
		return array_.size1();
	}

	// Size of Dimension 1
	inline
	size_type
	size1() const
	{
		return array_.size1();
	}

	// IndexRange of Dimension 2
	inline
	IR
	I2() const
	{
		return IR( 1, u2() );
	}

	// Lower Index of Dimension 2
	inline
	int
	l2() const
	{
		return 2;
	}

	// Upper Index of Dimension 2
	inline
	int
	u2() const
	{
		return array_.size2();
	}

	// Size of Dimension 2
	inline
	size_type
	size2() const
	{
		return array_.size2();
	}

	// IndexRange of Dimension 3
	inline
	IR
	I3() const
	{
		return IR( 1, u3() );
	}

	// Lower Index of Dimension 3
	inline
	int
	l3() const
	{
		return 3;
	}

	// Upper Index of Dimension 3
	inline
	int
	u3() const
	{
		return array_.size3();
	}

	// Size of Dimension 3
	inline
	size_type
	size3() const
	{
		return array_.size3();
	}

	// IndexRange of Dimension 4
	inline
	IR
	I4() const
	{
		return IR( 1, u4() );
	}

	// Lower Index of Dimension 4
	inline
	int
	l4() const
	{
		return 4;
	}

	// Upper Index of Dimension 4
	inline
	int
	u4() const
	{
		return array_.size4();
	}

	// Size of Dimension 4
	inline
	size_type
	size4() const
	{
		return array_.size4();
	}

public: // Modifier

	// Assign Default Value to all Elements
	inline
	MArray4 &
	to_default()
	{
		for ( int i4 = 1, e4 = u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = u1(); i1 <= e1; ++i1 ) {
						operator()( i1, i2, i3, i4 ) = Traits::initial_value();
					}
				}
			}
		}
		return *this;
	}

public: // MArray Generators

	// Template Helpers
	template< typename U > class Wrapper {};
	typedef  typename std::conditional< std::is_class< T >::value, T, Wrapper< T > >::type  ClassT;

	// MArray Generator
	template< typename M >
	inline
	MArray4< MArray4 const, M >
	ma( M ClassT::* pmem ) const
	{
		return MArray4< MArray4 const, M >( *this, pmem );
	}

	// MArray Generator
	template< typename M >
	inline
	MArray4< MArray4, M >
	ma( M ClassT::* pmem )
	{
		return MArray4< MArray4, M >( *this, pmem );
	}

public: // Comparison: Predicate

	// MArray4 == MArray4
	inline
	friend
	bool
	eq( MArray4 const & a, MArray4 const & b )
	{
		assert( a.size_bounded() );
		assert( a.conformable( b ) );
		if ( ( &a == &b ) || a.empty() ) return true;
		for ( int i4 = 1, e4 = a.u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = a.u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = a.u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = a.u1(); i1 <= e1; ++i1 ) {
						if ( ! ( a( i1, i2, i3, i4 ) == b( i1, i2, i3, i4 ) ) ) return false;
					}
				}
			}
		}
		return true;
	}

	// MArray4 != MArray4
	inline
	friend
	bool
	ne( MArray4 const & a, MArray4 const & b )
	{
		return ! eq( a, b );
	}

	// MArray4 < MArray4
	inline
	friend
	bool
	lt( MArray4 const & a, MArray4 const & b )
	{
		assert( a.size_bounded() );
		assert( a.conformable( b ) );
		if ( ( &a == &b ) || a.empty() ) return false;
		for ( int i4 = 1, e4 = a.u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = a.u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = a.u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = a.u1(); i1 <= e1; ++i1 ) {
						if ( ! ( a( i1, i2, i3, i4 ) < b( i1, i2, i3, i4 ) ) ) return false;
					}
				}
			}
		}
		return true;
	}

	// MArray4 <= MArray4
	inline
	friend
	bool
	le( MArray4 const & a, MArray4 const & b )
	{
		assert( a.size_bounded() );
		assert( a.conformable( b ) );
		if ( ( &a == &b ) || a.empty() ) return true;
		for ( int i4 = 1, e4 = a.u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = a.u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = a.u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = a.u1(); i1 <= e1; ++i1 ) {
						if ( ! ( a( i1, i2, i3, i4 ) <= b( i1, i2, i3, i4 ) ) ) return false;
					}
				}
			}
		}
		return true;
	}

	// MArray4 > MArray4
	inline
	friend
	bool
	gt( MArray4 const & a, MArray4 const & b )
	{
		return lt( b, a );
	}

	// MArray4 >= MArray4
	inline
	friend
	bool
	ge( MArray4 const & a, MArray4 const & b )
	{
		return le( b, a );
	}

	// MArray4 == Value
	inline
	friend
	bool
	eq( MArray4 const & a, T const & t )
	{
		assert( a.size_bounded() );
		for ( int i4 = 1, e4 = a.u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = a.u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = a.u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = a.u1(); i1 <= e1; ++i1 ) {
						if ( ! ( a( i1, i2, i3, i4 ) == t ) ) return false;
					}
				}
			}
		}
		return true;
	}

	// MArray4 != Value
	inline
	friend
	bool
	ne( MArray4 const & a, T const & t )
	{
		return ! eq( a, t );
	}

	// MArray4 < Value
	inline
	friend
	bool
	lt( MArray4 const & a, T const & t )
	{
		assert( a.size_bounded() );
		if ( a.empty() ) return false;
		for ( int i4 = 1, e4 = a.u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = a.u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = a.u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = a.u1(); i1 <= e1; ++i1 ) {
						if ( ! ( a( i1, i2, i3, i4 ) < t ) ) return false;
					}
				}
			}
		}
		return true;
	}

	// MArray4 <= Value
	inline
	friend
	bool
	le( MArray4 const & a, T const & t )
	{
		assert( a.size_bounded() );
		if ( a.empty() ) return true;
		for ( int i4 = 1, e4 = a.u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = a.u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = a.u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = a.u1(); i1 <= e1; ++i1 ) {
						if ( ! ( a( i1, i2, i3, i4 ) <= t ) ) return false;
					}
				}
			}
		}
		return true;
	}

	// MArray4 > Value
	inline
	friend
	bool
	gt( MArray4 const & a, T const & t )
	{
		return lt( t, a );
	}

	// MArray4 >= Value
	inline
	friend
	bool
	ge( MArray4 const & a, T const & t )
	{
		return le( t, a );
	}

	// Value == MArray4
	inline
	friend
	bool
	eq( T const & t, MArray4 const & a )
	{
		return eq( a, t );
	}

	// Value != MArray4
	inline
	friend
	bool
	ne( T const & t, MArray4 const & a )
	{
		return ! eq( a, t );
	}

	// Value < MArray4
	inline
	friend
	bool
	lt( T const & t, MArray4 const & a )
	{
		assert( a.size_bounded() );
		if ( a.empty() ) return false;
		for ( int i4 = 1, e4 = a.u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = a.u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = a.u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = a.u1(); i1 <= e1; ++i1 ) {
						if ( ! ( t < a( i1, i2, i3, i4 ) ) ) return false;
					}
				}
			}
		}
		return true;
	}

	// Value <= MArray4
	inline
	friend
	bool
	le( T const & t, MArray4 const & a )
	{
		assert( a.size_bounded() );
		if ( a.empty() ) return true;
		for ( int i4 = 1, e4 = a.u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = a.u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = a.u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = a.u1(); i1 <= e1; ++i1 ) {
						if ( ! ( t <= a( i1, i2, i3, i4 ) ) ) return false;
					}
				}
			}
		}
		return true;
	}

	// Value > MArray4
	inline
	friend
	bool
	gt( T const & t, MArray4 const & a )
	{
		return lt( a, t );
	}

	// Value >= MArray4
	inline
	friend
	bool
	ge( T const & t, MArray4 const & a )
	{
		return le( a, t );
	}

public: // Comparison: Predicate: Any

	// Any MArray4 == MArray4
	inline
	friend
	bool
	any_eq( MArray4 const & a, MArray4 const & b )
	{
		assert( a.conformable( b ) );
		if ( a.empty() ) return false;
		if ( &a == &b ) return true;
		for ( int i4 = 1, e4 = a.u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = a.u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = a.u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = a.u1(); i1 <= e1; ++i1 ) {
						if ( a( i1, i2, i3, i4 ) == b( i1, i2, i3, i4 ) ) return true;
					}
				}
			}
		}
		return false;
	}

	// Any MArray4 != MArray4
	inline
	friend
	bool
	any_ne( MArray4 const & a, MArray4 const & b )
	{
		return ! eq( a, b );
	}

	// Any MArray4 < MArray4
	inline
	friend
	bool
	any_lt( MArray4 const & a, MArray4 const & b )
	{
		assert( a.conformable( b ) );
		if ( a.empty() ) return false;
		if ( &a == &b ) return false;
		for ( int i4 = 1, e4 = a.u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = a.u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = a.u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = a.u1(); i1 <= e1; ++i1 ) {
						if ( a( i1, i2, i3, i4 ) < b( i1, i2, i3, i4 ) ) return true;
					}
				}
			}
		}
		return false;
	}

	// Any MArray4 <= MArray4
	inline
	friend
	bool
	any_le( MArray4 const & a, MArray4 const & b )
	{
		assert( a.conformable( b ) );
		if ( a.empty() ) return false;
		if ( &a == &b ) return true;
		for ( int i4 = 1, e4 = a.u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = a.u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = a.u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = a.u1(); i1 <= e1; ++i1 ) {
						if ( a( i1, i2, i3, i4 ) <= b( i1, i2, i3, i4 ) ) return true;
					}
				}
			}
		}
		return false;
	}

	// Any MArray4 > MArray4
	inline
	friend
	bool
	any_gt( MArray4 const & a, MArray4 const & b )
	{
		return any_lt( b, a );
	}

	// Any MArray4 >= MArray4
	inline
	friend
	bool
	any_ge( MArray4 const & a, MArray4 const & b )
	{
		return any_le( b, a );
	}

	// Any MArray4 == Value
	inline
	friend
	bool
	any_eq( MArray4 const & a, T const & t )
	{
		if ( a.empty() ) return false;
		for ( int i4 = 1, e4 = a.u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = a.u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = a.u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = a.u1(); i1 <= e1; ++i1 ) {
						if ( a( i1, i2, i3, i4 ) == t ) return true;
					}
				}
			}
		}
		return false;
	}

	// Any MArray4 != Value
	inline
	friend
	bool
	any_ne( MArray4 const & a, T const & t )
	{
		return ! eq( a, t );
	}

	// Any MArray4 < Value
	inline
	friend
	bool
	any_lt( MArray4 const & a, T const & t )
	{
		if ( a.empty() ) return false;
		for ( int i4 = 1, e4 = a.u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = a.u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = a.u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = a.u1(); i1 <= e1; ++i1 ) {
						if ( a( i1, i2, i3, i4 ) < t ) return true;
					}
				}
			}
		}
		return false;
	}

	// Any MArray4 <= Value
	inline
	friend
	bool
	any_le( MArray4 const & a, T const & t )
	{
		if ( a.empty() ) return false;
		for ( int i4 = 1, e4 = a.u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = a.u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = a.u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = a.u1(); i1 <= e1; ++i1 ) {
						if ( a( i1, i2, i3, i4 ) <= t ) return true;
					}
				}
			}
		}
		return false;
	}

	// Any MArray4 > Value
	inline
	friend
	bool
	any_gt( MArray4 const & a, T const & t )
	{
		return any_lt( t, a );
	}

	// Any MArray4 >= Value
	inline
	friend
	bool
	any_ge( MArray4 const & a, T const & t )
	{
		return any_le( t, a );
	}

	// Any Value == MArray4
	inline
	friend
	bool
	any_eq( T const & t, MArray4 const & a )
	{
		return any_eq( a, t );
	}

	// Any Value != MArray4
	inline
	friend
	bool
	any_ne( T const & t, MArray4 const & a )
	{
		return ! eq( a, t );
	}

	// Any Value < MArray4
	inline
	friend
	bool
	any_lt( T const & t, MArray4 const & a )
	{
		if ( a.empty() ) return false;
		for ( int i4 = 1, e4 = a.u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = a.u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = a.u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = a.u1(); i1 <= e1; ++i1 ) {
						if ( t < a( i1, i2, i3, i4 ) ) return true;
					}
				}
			}
		}
		return false;
	}

	// Any Value <= MArray4
	inline
	friend
	bool
	any_le( T const & t, MArray4 const & a )
	{
		if ( a.empty() ) return false;
		for ( int i4 = 1, e4 = a.u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = a.u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = a.u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = a.u1(); i1 <= e1; ++i1 ) {
						if ( t <= a( i1, i2, i3, i4 ) ) return true;
					}
				}
			}
		}
		return false;
	}

	// Any Value > MArray4
	inline
	friend
	bool
	any_gt( T const & t, MArray4 const & a )
	{
		return any_lt( a, t );
	}

	// Any Value >= MArray4
	inline
	friend
	bool
	any_ge( T const & t, MArray4 const & a )
	{
		return any_le( a, t );
	}

public: // Comparison: Predicate: All

	// All MArray4 == MArray4
	inline
	friend
	bool
	all_eq( MArray4 const & a, MArray4 const & b )
	{
		return eq( a, b );
	}

	// All MArray4 != MArray4
	inline
	friend
	bool
	all_ne( MArray4 const & a, MArray4 const & b )
	{
		return ! any_eq( a, b );
	}

	// All MArray4 < MArray4
	inline
	friend
	bool
	all_lt( MArray4 const & a, MArray4 const & b )
	{
		return lt( a, b );
	}

	// All MArray4 <= MArray4
	inline
	friend
	bool
	all_le( MArray4 const & a, MArray4 const & b )
	{
		return le( a, b );
	}

	// All MArray4 > MArray4
	inline
	friend
	bool
	all_gt( MArray4 const & a, MArray4 const & b )
	{
		return gt( a, b );
	}

	// All MArray4 >= MArray4
	inline
	friend
	bool
	all_ge( MArray4 const & a, MArray4 const & b )
	{
		return ge( a, b );
	}

	// All MArray4 == Value
	inline
	friend
	bool
	all_eq( MArray4 const & a, T const & t )
	{
		return eq( a, t );
	}

	// All MArray4 != Value
	inline
	friend
	bool
	all_ne( MArray4 const & a, T const & t )
	{
		return ! any_eq( a, t );
	}

	// All MArray4 < Value
	inline
	friend
	bool
	all_lt( MArray4 const & a, T const & t )
	{
		return lt( a, t );
	}

	// All MArray4 <= Value
	inline
	friend
	bool
	all_le( MArray4 const & a, T const & t )
	{
		return le( a, t );
	}

	// All MArray4 > Value
	inline
	friend
	bool
	all_gt( MArray4 const & a, T const & t )
	{
		return gt( a, t );
	}

	// All MArray4 >= Value
	inline
	friend
	bool
	all_ge( MArray4 const & a, T const & t )
	{
		return ge( a, t );
	}

	// All Value == MArray4
	inline
	friend
	bool
	all_eq( T const & t, MArray4 const & a )
	{
		return eq( t, a );
	}

	// All Value != MArray4
	inline
	friend
	bool
	all_ne( T const & t, MArray4 const & a )
	{
		return ! any_eq( t, a );
	}

	// All Value < MArray4
	inline
	friend
	bool
	all_lt( T const & t, MArray4 const & a )
	{
		return lt( t, a );
	}

	// All Value <= MArray4
	inline
	friend
	bool
	all_le( T const & t, MArray4 const & a )
	{
		return le( t, a );
	}

	// All Value > MArray4
	inline
	friend
	bool
	all_gt( T const & t, MArray4 const & a )
	{
		return gt( t, a );
	}

	// All Value >= MArray4
	inline
	friend
	bool
	all_ge( T const & t, MArray4 const & a )
	{
		return ge( t, a );
	}

public: // Comparison: Count

	// Count MArray4 == MArray4
	inline
	friend
	size_type
	count_eq( MArray4 const & a, MArray4 const & b )
	{
		assert( a.conformable( b ) );
		if ( a.empty() ) return 0;
		if ( &a == &b ) return a.size_;
		size_type n( 0 );
		for ( int i4 = 1, e4 = a.u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = a.u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = a.u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = a.u1(); i1 <= e1; ++i1 ) {
						if ( a( i1, i2, i3, i4 ) == b( i1, i2, i3, i4 ) ) ++n;
					}
				}
			}
		}
		return n;
	}

	// Count MArray4 != MArray4
	inline
	friend
	size_type
	count_ne( MArray4 const & a, MArray4 const & b )
	{
		assert( a.conformable( b ) );
		if ( a.empty() ) return 0;
		if ( &a == &b ) return a.size_;
		size_type n( 0 );
		for ( int i4 = 1, e4 = a.u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = a.u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = a.u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = a.u1(); i1 <= e1; ++i1 ) {
						if ( a( i1, i2, i3, i4 ) != b( i1, i2, i3, i4 ) ) ++n;
					}
				}
			}
		}
		return n;
	}

	// Count MArray4 < MArray4
	inline
	friend
	size_type
	count_lt( MArray4 const & a, MArray4 const & b )
	{
		assert( a.conformable( b ) );
		if ( a.empty() ) return 0;
		if ( &a == &b ) return a.size_;
		size_type n( 0 );
		for ( int i4 = 1, e4 = a.u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = a.u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = a.u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = a.u1(); i1 <= e1; ++i1 ) {
						if ( a( i1, i2, i3, i4 ) < b( i1, i2, i3, i4 ) ) ++n;
					}
				}
			}
		}
		return n;
	}

	// Count MArray4 <= MArray4
	inline
	friend
	size_type
	count_le( MArray4 const & a, MArray4 const & b )
	{
		assert( a.conformable( b ) );
		if ( a.empty() ) return 0;
		if ( &a == &b ) return a.size_;
		size_type n( 0 );
		for ( int i4 = 1, e4 = a.u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = a.u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = a.u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = a.u1(); i1 <= e1; ++i1 ) {
						if ( a( i1, i2, i3, i4 ) <= b( i1, i2, i3, i4 ) ) ++n;
					}
				}
			}
		}
		return n;
	}

	// Count MArray4 > MArray4
	inline
	friend
	size_type
	count_gt( MArray4 const & a, MArray4 const & b )
	{
		assert( a.conformable( b ) );
		if ( a.empty() ) return 0;
		if ( &a == &b ) return a.size_;
		size_type n( 0 );
		for ( int i4 = 1, e4 = a.u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = a.u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = a.u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = a.u1(); i1 <= e1; ++i1 ) {
						if ( a( i1, i2, i3, i4 ) > b( i1, i2, i3, i4 ) ) ++n;
					}
				}
			}
		}
		return n;
	}

	// Count MArray4 >= MArray4
	inline
	friend
	size_type
	count_ge( MArray4 const & a, MArray4 const & b )
	{
		assert( a.conformable( b ) );
		if ( a.empty() ) return 0;
		if ( &a == &b ) return a.size_;
		size_type n( 0 );
		for ( int i4 = 1, e4 = a.u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = a.u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = a.u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = a.u1(); i1 <= e1; ++i1 ) {
						if ( a( i1, i2, i3, i4 ) >= b( i1, i2, i3, i4 ) ) ++n;
					}
				}
			}
		}
		return n;
	}

	// Count MArray4 == Value
	inline
	friend
	size_type
	count_eq( MArray4 const & a, T const & t )
	{
		if ( a.empty() ) return 0;
		size_type n( 0 );
		for ( int i4 = 1, e4 = a.u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = a.u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = a.u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = a.u1(); i1 <= e1; ++i1 ) {
						if ( a( i1, i2, i3, i4 ) == t ) ++n;
					}
				}
			}
		}
		return n;
	}

	// Count Value == MArray4
	inline
	friend
	size_type
	count_eq( T const & t, MArray4 const & a )
	{
		return count_eq( a, t );
	}

	// Count MArray4 != Value
	inline
	friend
	size_type
	count_ne( MArray4 const & a, T const & t )
	{
		if ( a.empty() ) return 0;
		size_type n( 0 );
		for ( int i4 = 1, e4 = a.u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = a.u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = a.u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = a.u1(); i1 <= e1; ++i1 ) {
						if ( a( i1, i2, i3, i4 ) != t ) ++n;
					}
				}
			}
		}
		return n;
	}

	// Count Value != MArray4
	inline
	friend
	size_type
	count_ne( T const & t, MArray4 const & a )
	{
		return count_ne( a, t );
	}

	// Count MArray4 < Value
	inline
	friend
	size_type
	count_lt( MArray4 const & a, T const & t )
	{
		if ( a.empty() ) return 0;
		size_type n( 0 );
		for ( int i4 = 1, e4 = a.u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = a.u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = a.u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = a.u1(); i1 <= e1; ++i1 ) {
						if ( a( i1, i2, i3, i4 ) < t ) ++n;
					}
				}
			}
		}
		return n;
	}

	// Count Value < MArray4
	inline
	friend
	size_type
	count_lt( T const & t, MArray4 const & a )
	{
		return count_gt( a, t );
	}

	// Count MArray4 <= Value
	inline
	friend
	size_type
	count_le( MArray4 const & a, T const & t )
	{
		if ( a.empty() ) return 0;
		size_type n( 0 );
		for ( int i4 = 1, e4 = a.u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = a.u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = a.u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = a.u1(); i1 <= e1; ++i1 ) {
						if ( a( i1, i2, i3, i4 ) <= t ) ++n;
					}
				}
			}
		}
		return n;
	}

	// Count Value <= MArray4
	inline
	friend
	size_type
	count_le( T const & t, MArray4 const & a )
	{
		return count_ge( a, t );
	}

	// Count MArray4 > Value
	inline
	friend
	size_type
	count_gt( MArray4 const & a, T const & t )
	{
		if ( a.empty() ) return 0;
		size_type n( 0 );
		for ( int i4 = 1, e4 = a.u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = a.u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = a.u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = a.u1(); i1 <= e1; ++i1 ) {
						if ( a( i1, i2, i3, i4 ) > t ) ++n;
					}
				}
			}
		}
		return n;
	}

	// Count Value > MArray4
	inline
	friend
	size_type
	count_gt( T const & t, MArray4 const & a )
	{
		return count_lt( a, t );
	}

	// Count MArray4 >= Value
	inline
	friend
	size_type
	count_ge( MArray4 const & a, T const & t )
	{
		if ( a.empty() ) return 0;
		size_type n( 0 );
		for ( int i4 = 1, e4 = a.u4(); i4 <= e4; ++i4 ) {
			for ( int i3 = 1, e3 = a.u3(); i3 <= e3; ++i3 ) {
				for ( int i2 = 1, e2 = a.u2(); i2 <= e2; ++i2 ) {
					for ( int i1 = 1, e1 = a.u1(); i1 <= e1; ++i1 ) {
						if ( a( i1, i2, i3, i4 ) >= t ) ++n;
					}
				}
			}
		}
		return n;
	}

	// Count Value >= MArray4
	inline
	friend
	size_type
	count_ge( T const & t, MArray4 const & a )
	{
		return count_le( a, t );
	}

}; // MArray4

// Functions

// Make a MArray4
template< class A, typename T >
inline
MArray4< A, T >
make_MArray4( A & array, T A::value_type::* pmem )
{
	return MArray4< A, T >( array, pmem );
}

// Make a MArray4
template< class A, typename T >
inline
MArray4< A, T >
MA4( A & array, T A::value_type::* pmem )
{
	return MArray4< A, T >( array, pmem );
}

// Conformable?
template< typename Aa, typename Ta, typename Ab, typename Tb >
inline
bool
conformable( MArray4< Aa, Ta > const & a, MArray4< Ab, Tb > const & b )
{
	return a.conformable( b );
}

// Equal Dimensions?
template< typename Aa, typename Ta, typename Ab, typename Tb >
inline
bool
equal_dimensions( MArray4< Aa, Ta > const & a, MArray4< Ab, Tb > const & b )
{
	return a.equal_dimensions( b );
}

} // ObjexxFCL

#endif // ObjexxFCL_MArray4_hh_INCLUDED
