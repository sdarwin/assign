/**
 * Non-intrusive Assignment Library
 * (C) Thorsten Ottosen 2002-2003
 * 
 * Permission to copy, use, modify,
 * sell and distribute this software is granted provided this
 * copyright notice appears in all copies. This software is provided
 * "as is" without express or implied warranty, and with no claim as
 * to its suitability for any purpose.
 *
 * See http://www.boost.org/libs/assign for documentation.
 *
 */

#ifndef BOOST_ASSIGN_INSERT_ASSIGNER_HPP
#define BOOST_ASSIGN_INSERT_ASSIGNER_HPP

namespace boost
{
    
    namespace assignment
    {
        namespace detail
        {
                
            template< typename C, typename V = typename C::value_type > 
            class insert_assigner
            {
            public:
                typedef V  value_type;
    
                explicit insert_assigner( C& c ) : c_( c )
                {}
    
    
    
                insert_assigner( C& c, const value_type& v )
                : c_( c )
                {
                    insert( c_, v );
                }
    
    
    
                insert_assigner& operator,( const value_type& v )
                {
                    insert( c_, v );
                    return *this;
                }
    
    
                /*
                insert_assigner& operator<<( const value-type& v )
                {
                    insert( c_, v );
                    return *this;
                }*/
    
    
    
                template< typename T, typename T2 >
                insert_assigner& operator()( const T& t, const T2& t2 )
                {
                    insert( c_, value_type( t, t2 ) );
                    return *this;
                }
    
    
    
                template< typename T, typename T2, typename T3 >
                insert_assigner& operator()( const T& t, const T2& t2, const T3& t3 )
                {
                    insert( c_, value_type( t, t2, t3 ) );
                    return *this;
                }
    
    
    
                template< typename T, typename T2, typename T3, typename T4 >
                insert_assigner& operator()( const T& t, const T2& t2, const T3& t3,
                                      const T4& t4 )
                {
                    insert( c_, value_type( t, t2, t3, t4 ) );
                    return *this;
                }
    
    
    
                template< typename T, typename T2, typename T3, typename T4,
                typename T5 >
                insert_assigner& operator()( const T& t, const T2& t2, const T3& t3,
                                      const T4& t4, const T5& t5 )
                {
                    insert( c_, value_type( t, t2, t3, t4, t5 ) );
                    return *this;
                }
    
    
    
                template< typename T, typename T2, typename T3, typename T4,
                typename T5, typename T6 >
                insert_assigner& operator()( const T& t, const T2& t2, const T3& t3,
                                      const T4& t4, const T5& t5, const T6& t6 )
                {
                    insert( c_, value_type( t, t2, t3, t4, t5, t6 ) );
                    return *this;
                }
    
            private:
    
                insert_assigner& operator=( const insert_assigner& );
                C& c_;
            };
            
        } // namespace 'detail'
    } // namespace 'assignment'
} // namespace 'boost'

#endif