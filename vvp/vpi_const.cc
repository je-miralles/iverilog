/*
 * Copyright (c) 2001 Stephen Williams (steve@icarus.com)
 *
 *    This source code is free software; you can redistribute it
 *    and/or modify it in source code form under the terms of the GNU
 *    General Public License as published by the Free Software
 *    Foundation; either version 2 of the License, or (at your option)
 *    any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program; if not, write to the Free Software
 *    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 */
#if !defined(WINNT)
#ident "$Id: vpi_const.cc,v 1.2 2001/04/02 00:24:31 steve Exp $"
#endif

# include  "vpi_priv.h"
# include  <malloc.h>
# include  <string.h>
# include  <assert.h>

static int string_get(int code, vpiHandle ref)
{
      struct __vpiStringConst*rfp = (struct __vpiStringConst*)ref;
      assert(ref->vpi_type->type_code == vpiConstant);

      switch (code) {
	  case vpiConstType:
	    return vpiStringConst;

	  default:
	    assert(0);
	    return 0;
      }
}

static void string_value(vpiHandle ref, p_vpi_value vp)
{
      struct __vpiStringConst*rfp = (struct __vpiStringConst*)ref;
      assert(ref->vpi_type->type_code == vpiConstant);

      switch (vp->format) {
	  case vpiObjTypeVal:
	  case vpiStringVal:
	    vp->value.str = (char*)rfp->value;
	    vp->format = vpiStringVal;
	    break;

	  default:
	    vp->format = vpiSuppressVal;
	    break;
      }
}


static const struct __vpirt vpip_string_rt = {
      vpiConstant,
      string_get,
      0,
      string_value,
      0,
      0,
      0
};


vpiHandle vpip_make_string_const(char*text)
{
      struct __vpiStringConst*obj;

      obj = (struct __vpiStringConst*)
	    malloc(sizeof (struct __vpiStringConst));
      obj->base.vpi_type = &vpip_string_rt;
      obj->value = text;

      return &obj->base;
}


static int binary_get(int code, vpiHandle ref)
{
      struct __vpiBinaryConst*rfp = (struct __vpiBinaryConst*)ref;
      assert(ref->vpi_type->type_code == vpiConstant);

      switch (code) {
	  case vpiConstType:
	    return vpiBinaryConst;

	  default:
	    assert(0);
	    return 0;
      }
}

static void binary_value(vpiHandle ref, p_vpi_value vp)
{
      struct __vpiStringConst*rfp = (struct __vpiStringConst*)ref;
      assert(ref->vpi_type->type_code == vpiConstant);

      switch (vp->format) {

	  default:
	    vp->format = vpiSuppressVal;
	    break;
      }
}

static const struct __vpirt vpip_binary_rt = {
      vpiConstant,
      binary_get,
      0,
      binary_value,
      0,
      0,
      0
};

vpiHandle vpip_make_binary_const(long val)
{
      struct __vpiBinaryConst*obj;

      obj = (struct __vpiBinaryConst*)
	    malloc(sizeof (struct __vpiBinaryConst));
      obj->base.vpi_type = &vpip_binary_rt;

      obj->nbits = 8*sizeof(long);
      obj->bits = (unsigned char*)malloc(obj->nbits / 4);
      memset(obj->bits, 0, obj->nbits / 4);

      for (unsigned idx = 0 ;  idx < obj->nbits ;  idx += 1) {
	    unsigned nibble = idx / 4;

	    if (val & 1)
		  obj->bits[nibble] |= 1 << 2 * (idx%4);

	    val >>= 1;
      }

      return &(obj->base);
}


/*
 * $Log: vpi_const.cc,v $
 * Revision 1.2  2001/04/02 00:24:31  steve
 *  Take numbers as system task parameters.
 *
 * Revision 1.1  2001/03/18 04:35:18  steve
 *  Add support for string constants to VPI.
 *
 */

