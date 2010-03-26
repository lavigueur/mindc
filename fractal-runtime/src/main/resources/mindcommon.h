/**
 * Fractal Runtime
 *
 * Copyright (C) 2010 STMicroelectronics
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 *
 * Contact: mind@ow2.org
 *
 * Authors: Matthieu Leclercq
 */
#ifndef __MIND_COMMON_H
#define __MIND_COMMON_H

/*
 * This file contains MIND common types and macro definitions. These definitions
 * can be configured thank to various "configuration macros". These
 * configuration macros can be set in various way :
 *  - in the mindc command-line with the --c-flag option;
 *  - in a target descriptor to specialise these common definitions for a given
 *    platform or C compiler;
 *  - in an ADL definition with the @CFlag annotation do specialize these common
 *    definitions for a given component.
 */

/*
 * If the __MIND_USERINCLUDE_H macro is defined, it must be a path to an header
 * file that is included here. This header file may contain macro definitions
 * used in the rest of this file.
 */
#ifdef __MIND_USERINCLUDE_H
#include __MIND_USERINCLUDE_H
#endif

/*
 * Include <stdint.h>.
 * The __MIND_NO_STDINT_H macro can be defined to avoid the inclusion of
 * <stdint.h>.
 * The __MIND_STDINT_H macro can be defined to override the path to the
 * <stdint.h> file.
 */
#ifndef __MIND_NO_STDINT_H
#ifndef __MIND_STDINT_H
#define __MIND_STDINT_H <stdint.h>
#endif
#include __MIND_STDINT_H
#endif

/*
 * Include <stddef.h>.
 * The __MIND_NO_STDDEF_H macro can be defined to avoid the inclusion of
 * <stddef.h>.
 * The __MIND_STDDEF_H macro can be defined to override the path to the
 * <stddef.h> file.
 */
#ifndef __MIND_NO_STDDEF_H
#ifndef __MIND_STDDEF_H
#define __MIND_STDDEF_H <stddef.h>
#endif
#include __MIND_STDDEF_H
#endif

/*
 * Defines the "string" type.
 * The __MIND_STRING_TYPE macro can be defined to override the default
 * definition of the "string" type. (default definition is "const char *").
 * The __MIND_NO_STRING_TYPEDEF macro can be defined to avoid the definition
 * of the "string" typedef.
 * Note that the code generated by mindc, do not use the "string" typedef
 * directly. It uses instead the __MIND_STRING_TYPEDEF macro. This macro expands
 * to __MIND_STRING_TYPE if the __MIND_NO_STRING_TYPEDEF macro is defined,
 * otherwise it expands to "string".
 */
#ifndef __MIND_STRING_TYPE
#define __MIND_STRING_TYPE const char *
#endif
#ifndef __MIND_NO_STRING_TYPEDEF
typedef __MIND_STRING_TYPE string;
#define __MIND_STRING_TYPEDEF string
#define __MIND_CONST_STRING_TYPEDEF const string
#else
#define __MIND_STRING_TYPEDEF __MIND_STRING_TYPE
#define __MIND_CONST_STRING_TYPEDEF __MIND_STRING_TYPE const
#endif

/**
 * The __MIND_STRICT_C89 macro can be used to force the generated code to be
 * strictly compliant with C89. If this macro is defined, this implies that the
 * __MIND_NO_INLINE and the __MIND_NO_GCC_ATTRIBUTE macros are defined.
 */
#ifdef __MIND_STRICT_C89
#define __MIND_NO_INLINE
#define __MIND_NO_GCC_ATTRIBUTE
#endif

/*
 * Defines the __MIND_INLINE macro. This macro expands to the "inline" keyword,
 * and is used in the code generated by mindc.
 * The __MIND_NO_INLINE macro can be defined to avoid the use of "inline"
 * keyword in the generated code. (This is required to compile code in stdc89)
 */
#ifndef __MIND_INLINE
#ifdef __MIND_NO_INLINE
#define __MIND_INLINE
#else
#define __MIND_INLINE inline
#endif
#endif

/*
 * The __MIND_NO_GCC_ATTRIBUTE macro can be defined to avoid the use of gcc
 * attribute in the generated code. Note that if the __MIND_NO_GCC_ATTRIBUTE is
 * defined, the compilation of the generated code may raise some warnings when
 * compiled with GCC with the "-Wall" flag.
 */
#ifndef __MIND_ATTRIBUTE
#ifdef __MIND_NO_GCC_ATTRIBUTE
#define __MIND_ATTRIBUTE(attr)
#else
#define __MIND_ATTRIBUTE(attr) __attribute__(attr)
#endif
#endif

/**
 * The __MIND_ATTRIBUTE_UNUSED macro is used to add the "unused" GCC attribute
 * to some generated functions.
 */
#ifndef __MIND_ATTRIBUTE_UNUSED
#define __MIND_ATTRIBUTE_UNUSED __MIND_ATTRIBUTE((unused))
#endif

#endif