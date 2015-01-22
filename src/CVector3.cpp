#include "CVector3.h"

#define POW2(x) (x*x)

// ---------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------
//                                          Constructors
// ---------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------
// Default constructor
// ---------------------------------------------------------------------------------------------
CVector3::CVector3()
{
    m_fX = 0.0;
    m_fY = 0.0;
    m_fZ = 0.0;
}

// ---------------------------------------------------------------------------------------------
// Construction and initializer
// ---------------------------------------------------------------------------------------------
CVector3::CVector3(float _fX, float _fY, float _fZ)
{
    m_fX = _fX;
    m_fY = _fY;
    m_fZ = _fZ;
}

// ---------------------------------------------------------------------------------------------
// Copy constructor
// ---------------------------------------------------------------------------------------------
CVector3::CVector3(CVector3 const& _oSrc)
{
    m_fX = _oSrc.m_fX;
    m_fY = _oSrc.m_fY;
    m_fZ = _oSrc.m_fZ;
}

// ---------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------
//                                          Member functions
// ---------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------
// Set the vector to the three parameter values
// ---------------------------------------------------------------------------------------------
void CVector3::vSet(float _fX, float _fY, float _fZ)
{
    m_fX = _fX;
    m_fY = _fY;
    m_fZ = _fZ;
}

// ---------------------------------------------------------------------------------------------
// Set the vector to the value of the 3d vector parameter
// ---------------------------------------------------------------------------------------------
void CVector3::vSet(CVector3 const & _oSrc)
{
    m_fX = _oSrc.m_fX;
    m_fY = _oSrc.m_fY;
    m_fZ = _oSrc.m_fZ;
}

// ---------------------------------------------------------------------------------------------
// Set the 3DVector to the vectorial product between A and B.
// ---------------------------------------------------------------------------------------------
void CVector3::vCross(CVector3 const& _oA, const CVector3 &_oB)
{
    m_fX = _oA.m_fY * _oB.m_fZ - _oA.m_fZ * _oB.m_fY;
    m_fY = _oA.m_fZ * _oB.m_fX - _oA.m_fX * _oB.m_fZ;
    m_fZ = _oA.m_fX * _oB.m_fY - _oA.m_fY * _oB.m_fX;
}

// ---------------------------------------------------------------------------------------------
// Returns the scalar product with another 3D vector
// ---------------------------------------------------------------------------------------------
float CVector3::fDot(CVector3 const& _oB)
{
    return (m_fX * _oB.m_fX + m_fY * _oB.m_fY + m_fZ * _oB.m_fZ);
}

// ---------------------------------------------------------------------------------------------
// Normalise the vector and returns 1 if succeed, 0 otherwise.
// Normalize() will fail if the norm of the vector is 0.
// ---------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------
//                                     Overloaded operations
// ---------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------
// Computes CVector3 = CVector3 + CVector3
// ---------------------------------------------------------------------------------------------
CVector3 operator+ (CVector3 const& _oA, CVector3 const& _oB)
{
    return CVector3(_oA.m_fX + _oB.m_fX, _oA.m_fY + _oB.m_fY, _oA.m_fZ + _oB.m_fZ);
}

// ---------------------------------------------------------------------------------------------
// Computes CVector3 = CVector3 - CVector3
// ---------------------------------------------------------------------------------------------
CVector3 operator- (CVector3 const& _oA, CVector3 const& _oB)
{
    return CVector3(_oA.m_fX - _oB.m_fX, _oA.m_fY - _oB.m_fY, _oA.m_fZ - _oB.m_fZ);
}

// ---------------------------------------------------------------------------------------------
// Computes CVector3 += CVector3
// ---------------------------------------------------------------------------------------------
void operator+= (CVector3 & _oA, CVector3 const& _oB)
{
    _oA.m_fX += _oB.m_fX;
    _oA.m_fY += _oB.m_fY;
    _oA.m_fZ += _oB.m_fZ;
}
