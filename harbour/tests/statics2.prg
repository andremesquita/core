/*
 * $Id$
 */

// Statics overlapped!
//
// Compile statics1.prg, statics2.prg and link both files

STATIC uA, uB

PROCEDURE Test()

   ? "INSIDE statics2.prg"
   ? "   static uA, uB"
   ?
   ? "   ValType( uA ), ValType( uB ) =>", ValType( uA ), ",", ValType( uB )
   ? "   uA, uB =>", uA, ",", uB
   uA := "a"
   uB := "b"
   ? '   uA := "a"'
   ? '   uB := "b"'
   ? "   uA, uB =>", uA, ",", uB
   ?

   RETURN
