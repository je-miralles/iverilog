/*
 * Copyright (c) 2003 Stephen Williams (steve at icarus.com)
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
#ifdef HAVE_CVS_IDENT
#ident "$Id: xilinx.c,v 1.2 2003/06/25 02:55:57 steve Exp $"
#endif

# include  "edif.h"
# include  "generic.h"
# include  "xilinx.h"
# include  <stdlib.h>
# include  <string.h>
#ifdef HAVE_MALLOC_H
# include  <malloc.h>
#endif
# include  <assert.h>

edif_cell_t xilinx_cell_buf(edif_xlibrary_t xlib)
{
      static edif_cell_t cell = 0;
      if (cell) return cell;

      cell = edif_xcell_create(xlib, "BUF", 2);
      edif_cell_portconfig(cell, BUF_O, "O", IVL_SIP_OUTPUT);
      edif_cell_portconfig(cell, BUF_I, "I", IVL_SIP_INPUT);
      return cell;
}

edif_cell_t xilinx_cell_bufg(edif_xlibrary_t xlib)
{
      static edif_cell_t cell = 0;
      if (cell) return cell;

      cell = edif_xcell_create(xlib, "BUFG", 2);
      edif_cell_portconfig(cell, BUF_O, "O", IVL_SIP_OUTPUT);
      edif_cell_portconfig(cell, BUF_I, "I", IVL_SIP_INPUT);
      return cell;
}

edif_cell_t xilinx_cell_ibuf(edif_xlibrary_t xlib)
{
      static edif_cell_t cell = 0;
      if (cell) return cell;

      cell = edif_xcell_create(xlib, "IBUF", 2);
      edif_cell_portconfig(cell, BUF_O, "O", IVL_SIP_OUTPUT);
      edif_cell_portconfig(cell, BUF_I, "I", IVL_SIP_INPUT);
      return cell;
}

edif_cell_t xilinx_cell_inv(edif_xlibrary_t xlib)
{
      static edif_cell_t cell = 0;
      if (cell) return cell;

      cell = edif_xcell_create(xlib, "INV", 2);
      edif_cell_portconfig(cell, BUF_O, "O", IVL_SIP_OUTPUT);
      edif_cell_portconfig(cell, BUF_I, "I", IVL_SIP_INPUT);
      return cell;
}

edif_cell_t xilinx_cell_obuf(edif_xlibrary_t xlib)
{
      static edif_cell_t cell = 0;
      if (cell) return cell;

      cell = edif_xcell_create(xlib, "OBUF", 2);
      edif_cell_portconfig(cell, BUF_O, "O", IVL_SIP_OUTPUT);
      edif_cell_portconfig(cell, BUF_I, "I", IVL_SIP_INPUT);
      return cell;
}


edif_cell_t xilinx_cell_lut2(edif_xlibrary_t xlib)
{
      static edif_cell_t cell = 0;
      if (cell != 0) return cell;

      cell = edif_xcell_create(xlib, "LUT2", 3);
      edif_cell_portconfig(cell, LUT_O,  "O",  IVL_SIP_OUTPUT);
      edif_cell_portconfig(cell, LUT_I0, "I0", IVL_SIP_INPUT);
      edif_cell_portconfig(cell, LUT_I1, "I1", IVL_SIP_INPUT);
      return cell;
}

edif_cell_t xilinx_cell_lut3(edif_xlibrary_t xlib)
{
      static edif_cell_t cell = 0;
      if (cell != 0) return cell;

      cell = edif_xcell_create(xlib, "LUT3", 4);
      edif_cell_portconfig(cell, LUT_O,  "O",  IVL_SIP_OUTPUT);
      edif_cell_portconfig(cell, LUT_I0, "I0", IVL_SIP_INPUT);
      edif_cell_portconfig(cell, LUT_I1, "I1", IVL_SIP_INPUT);
      edif_cell_portconfig(cell, LUT_I2, "I2", IVL_SIP_INPUT);
      return cell;
}

edif_cell_t xilinx_cell_lut4(edif_xlibrary_t xlib)
{
      static edif_cell_t cell = 0;
      if (cell != 0) return cell;

      cell = edif_xcell_create(xlib, "LUT4", 5);
      edif_cell_portconfig(cell, LUT_O,  "O",  IVL_SIP_OUTPUT);
      edif_cell_portconfig(cell, LUT_I0, "I0", IVL_SIP_INPUT);
      edif_cell_portconfig(cell, LUT_I1, "I1", IVL_SIP_INPUT);
      edif_cell_portconfig(cell, LUT_I2, "I2", IVL_SIP_INPUT);
      edif_cell_portconfig(cell, LUT_I3, "I3", IVL_SIP_INPUT);
      return cell;
}


edif_cell_t xilinx_cell_fdce(edif_xlibrary_t xlib)
{
      static edif_cell_t cell = 0;
      if (cell != 0) return cell;

      cell = edif_xcell_create(xlib, "FDCE", 5);
      edif_cell_portconfig(cell, FDCE_Q,  "Q",   IVL_SIP_INPUT);
      edif_cell_portconfig(cell, FDCE_D,  "D",   IVL_SIP_OUTPUT);
      edif_cell_portconfig(cell, FDCE_C,  "C",   IVL_SIP_INPUT);
      edif_cell_portconfig(cell, FDCE_CE, "CE",  IVL_SIP_INPUT);
      edif_cell_portconfig(cell, FDCE_CLR,"CLR", IVL_SIP_INPUT);
      return cell;
}

edif_cell_t xilinx_cell_fdcpe(edif_xlibrary_t xlib)
{
      static edif_cell_t cell = 0;
      if (cell != 0) return cell;

      cell = edif_xcell_create(xlib, "FDCPE", 6);
      edif_cell_portconfig(cell, FDCE_Q,  "Q",   IVL_SIP_INPUT);
      edif_cell_portconfig(cell, FDCE_D,  "D",   IVL_SIP_OUTPUT);
      edif_cell_portconfig(cell, FDCE_C,  "C",   IVL_SIP_INPUT);
      edif_cell_portconfig(cell, FDCE_CE, "CE",  IVL_SIP_INPUT);
      edif_cell_portconfig(cell, FDCE_CLR,"CLR", IVL_SIP_INPUT);
      edif_cell_portconfig(cell, FDCE_PRE,"PRE", IVL_SIP_INPUT);
      return cell;
}


edif_cell_t xilinx_cell_mult_and(edif_xlibrary_t xlib)
{
      static edif_cell_t cell = 0;
      if (cell != 0) return cell;

      cell = edif_xcell_create(xlib, "MULT_AND", 3);
      edif_cell_portconfig(cell, MULT_AND_LO, "LO", IVL_SIP_OUTPUT);
      edif_cell_portconfig(cell, MULT_AND_I0, "I0", IVL_SIP_INPUT);
      edif_cell_portconfig(cell, MULT_AND_I1, "I1", IVL_SIP_INPUT);
      return cell;
}

edif_cell_t xilinx_cell_muxcy(edif_xlibrary_t xlib)
{
      static edif_cell_t cell = 0;
      if (cell != 0) return cell;

      cell = edif_xcell_create(xlib, "MUXCY", 4);
      edif_cell_portconfig(cell, MUXCY_O,  "O",  IVL_SIP_OUTPUT);
      edif_cell_portconfig(cell, MUXCY_DI, "DI", IVL_SIP_INPUT);
      edif_cell_portconfig(cell, MUXCY_CI, "CI", IVL_SIP_INPUT);
      edif_cell_portconfig(cell, MUXCY_S,  "S",  IVL_SIP_INPUT);
      return cell;
}

edif_cell_t xilinx_cell_muxcy_l(edif_xlibrary_t xlib)
{
      static edif_cell_t cell = 0;
      if (cell != 0) return cell;

      cell = edif_xcell_create(xlib, "MUXCY_L", 4);
      edif_cell_portconfig(cell, MUXCY_O,  "LO", IVL_SIP_OUTPUT);
      edif_cell_portconfig(cell, MUXCY_DI, "DI", IVL_SIP_INPUT);
      edif_cell_portconfig(cell, MUXCY_CI, "CI", IVL_SIP_INPUT);
      edif_cell_portconfig(cell, MUXCY_S,  "S",  IVL_SIP_INPUT);
      return cell;
}

edif_cell_t xilinx_cell_xorcy(edif_xlibrary_t xlib)
{
      static edif_cell_t cell = 0;
      if (cell != 0) return cell;

      cell = edif_xcell_create(xlib, "XORCY", 3);
      edif_cell_portconfig(cell, XORCY_O,  "O",  IVL_SIP_OUTPUT);
      edif_cell_portconfig(cell, XORCY_CI, "CI", IVL_SIP_INPUT);
      edif_cell_portconfig(cell, XORCY_LI, "LI", IVL_SIP_INPUT);
      return cell;
}

/*
 * Make (or retrieve) a cell in the external library that reflects the
 * scope with its ports.
 */
void xilinx_show_scope(ivl_scope_t scope)
{
      edif_cell_t cell;
      edif_cellref_t ref;

      unsigned port, idx;

      cell = edif_xlibrary_scope_cell(xlib, scope);
      ref = edif_cellref_create(edf, cell);

      for (idx = 0 ;  idx < ivl_scope_sigs(scope) ;  idx += 1) {
	    edif_joint_t jnt;
	    ivl_signal_t sig = ivl_scope_sig(scope, idx);

	    if (ivl_signal_port(sig) == IVL_SIP_NONE)
		  continue;

	    port = edif_cell_port_byname(cell, ivl_signal_basename(sig));
	    jnt = edif_joint_of_nexus(edf, ivl_signal_pin(sig, 0));
	    edif_add_to_joint(jnt, ref, port);
      }
}

void xilinx_pad(ivl_signal_t sig, const char*str)
{
      unsigned idx;
      unsigned*pins;

      if (cell_ipad == 0) {
	    cell_ipad = edif_xcell_create(xlib, "IPAD", 1);
	    edif_cell_portconfig(cell_ipad, 0, "IPAD", IVL_SIP_OUTPUT);
      }

      if (cell_opad == 0) {
	    cell_opad = edif_xcell_create(xlib, "OPAD", 1);
	    edif_cell_portconfig(cell_opad, 0, "OPAD", IVL_SIP_OUTPUT);
      }

	/* Collect an array of pin assignments from the attribute
	   string passed in as str. The format is a comma separated
	   list of unsigned decimal integers. */
      pins = calloc(ivl_signal_pins(sig), sizeof(unsigned));
      for (idx = 0 ;  idx < ivl_signal_pins(sig) ;  idx += 1) {
	    char*tmp;
	    pins[idx] = strtoul(str, &tmp, 10);
	    switch (*tmp) {
		case ',':
		  tmp += 1;
		  break;
		case 0:
		  break;
		default:
		  assert(0);
	    }

	    str = tmp;
      }

	/* Now go through the pins of the signal, creating pads and
	   bufs and joining them to the signal nexus. */
      for (idx = 0 ;  idx < ivl_signal_pins(sig) ;  idx += 1) {
	    edif_joint_t jnt;
	    edif_cellref_t pad, buf;

	    const char*name_str = ivl_signal_basename(sig);
	    if (ivl_signal_pins(sig) > 1) {
		  char name_buf[128];
		  sprintf(name_buf, "%s[%u]", name_str, idx);
		  name_str = strdup(name_buf);
	    }

	    switch (ivl_signal_port(sig)) {
		case IVL_SIP_INPUT:
		  pad = edif_cellref_create(edf, cell_ipad);
		  buf = edif_cellref_create(edf, xilinx_cell_ibuf(xlib));

		  jnt = edif_joint_create(edf);
		  edif_joint_rename(jnt, name_str);
		  edif_add_to_joint(jnt, pad, 0);
		  edif_add_to_joint(jnt, buf, BUF_I);

		  jnt = edif_joint_of_nexus(edf, ivl_signal_pin(sig, idx));
		  edif_add_to_joint(jnt, buf, BUF_O);
		  break;

		case IVL_SIP_OUTPUT:
		  pad = edif_cellref_create(edf, cell_opad);
		  buf = edif_cellref_create(edf, xilinx_cell_obuf(xlib));

		  jnt = edif_joint_create(edf);
		  edif_joint_rename(jnt, name_str);
		  edif_add_to_joint(jnt, pad, 0);
		  edif_add_to_joint(jnt, buf, BUF_O);

		  jnt = edif_joint_of_nexus(edf, ivl_signal_pin(sig, idx));
		  edif_add_to_joint(jnt, buf, BUF_I);
		  break;

		default:
		  assert(0);
	    }

      }

      free(pins);
}

/*
 * This function handles the case where the user specifies the cell to
 * use by attribute.
 */
static void edif_cellref_logic(ivl_net_logic_t net, const char*def)
{
      char*str = strdup(def);
      char*pins;
      edif_cell_t cell;
      edif_cellref_t ref;
      edif_joint_t jnt;
      unsigned idx, port;

      pins = strchr(str, ':');
      assert(pins);
      *pins++ = 0;

	/* Locate the cell in the library, lookup by name. */
      cell = edif_xlibrary_findcell(xlib, str);
      assert(cell);

      ref = edif_cellref_create(edf, cell);

      for (idx = 0 ;  idx < ivl_logic_pins(net) ;  idx += 1) {
	    char*tmp;

	    assert(pins);
	    tmp = strchr(pins,',');
	    if (tmp != 0)
		  *tmp++ = 0;
	    else
		  tmp = 0;

	    port = edif_cell_port_byname(cell, pins);
	    jnt = edif_joint_of_nexus(edf, ivl_logic_pin(net, idx));
	    edif_add_to_joint(jnt, ref, port);

	    pins = tmp;
      }

      free(str);
}

static void lut_logic(ivl_net_logic_t net, const char*init3,
		      const char*init4, const char*init5)
{
      edif_cellref_t lut;
      edif_joint_t jnt;
      const char* init;

      assert(ivl_logic_pins(net) <= 5);
      assert(ivl_logic_pins(net) >= 3);

      switch (ivl_logic_pins(net)) {
	  case 3:
	    lut = edif_cellref_create(edf, xilinx_cell_lut2(xlib));
	    init = init3;
	    break;

	  case 4:
	    lut = edif_cellref_create(edf, xilinx_cell_lut3(xlib));
	    init = init4;
	    break;

	  case 5:
	    lut = edif_cellref_create(edf, xilinx_cell_lut4(xlib));
	    init = init5;
	    break;
      }

      edif_cellref_pstring(lut, "INIT", init);

      switch (ivl_logic_pins(net)) {
	  case 5:
	    jnt = edif_joint_of_nexus(edf, ivl_logic_pin(net, 4));
	    edif_add_to_joint(jnt, lut, LUT_I3);
	  case 4:
	    jnt = edif_joint_of_nexus(edf, ivl_logic_pin(net, 3));
	    edif_add_to_joint(jnt, lut, LUT_I2);
	  case 3:
	    jnt = edif_joint_of_nexus(edf, ivl_logic_pin(net, 2));
	    edif_add_to_joint(jnt, lut, LUT_I1);
      }

      jnt = edif_joint_of_nexus(edf, ivl_logic_pin(net, 1));
      edif_add_to_joint(jnt, lut, LUT_I0);

      jnt = edif_joint_of_nexus(edf, ivl_logic_pin(net, 0));
      edif_add_to_joint(jnt, lut, LUT_O);
}


void xilinx_logic(ivl_net_logic_t net)
{
      edif_cellref_t obj;
      edif_joint_t   jnt;

      { const char*cellref_attribute = ivl_logic_attr(net, "cellref");
        if (cellref_attribute != 0) {
	      edif_cellref_logic(net, cellref_attribute);
	      return;
	}
      }

      switch (ivl_logic_type(net)) {

	  case IVL_LO_BUF:
	  case IVL_LO_BUFZ:
	    assert(ivl_logic_pins(net) == 2);

	    obj = edif_cellref_create(edf, xilinx_cell_buf(xlib));

	    jnt = edif_joint_of_nexus(edf, ivl_logic_pin(net, 0));
	    edif_add_to_joint(jnt, obj, BUF_O);

	    jnt = edif_joint_of_nexus(edf, ivl_logic_pin(net, 1));
	    edif_add_to_joint(jnt, obj, BUF_I);
	    break;

	  case IVL_LO_NOT:
	    assert(ivl_logic_pins(net) == 2);

	    obj = edif_cellref_create(edf, xilinx_cell_inv(xlib));

	    jnt = edif_joint_of_nexus(edf, ivl_logic_pin(net, 0));
	    edif_add_to_joint(jnt, obj, BUF_O);

	    jnt = edif_joint_of_nexus(edf, ivl_logic_pin(net, 1));
	    edif_add_to_joint(jnt, obj, BUF_I);
	    break;

	  case IVL_LO_AND:
	    assert(ivl_logic_pins(net) <= 5);
	    assert(ivl_logic_pins(net) >= 3);
	    lut_logic(net, "8", "80", "8000");
	    break;

	  case IVL_LO_NOR:
	    assert(ivl_logic_pins(net) <= 5);
	    assert(ivl_logic_pins(net) >= 3);
	    lut_logic(net, "1", "01", "0001");
	    break;

	  case IVL_LO_OR:
	    assert(ivl_logic_pins(net) <= 5);
	    assert(ivl_logic_pins(net) >= 3);
	    lut_logic(net, "E", "FE", "FFFE");
	    break;

	  case IVL_LO_XNOR:
	    assert(ivl_logic_pins(net) <= 5);
	    assert(ivl_logic_pins(net) >= 3);
	    lut_logic(net, "9", "69", "9669");
	    break;

	  case IVL_LO_XOR:
	    assert(ivl_logic_pins(net) <= 5);
	    assert(ivl_logic_pins(net) >= 3);
	    lut_logic(net, "6", "96", "6996");
	    break;

	  default:
	    fprintf(stderr, "UNSUPPORTED LOGIC TYPE: %u\n",
		    ivl_logic_type(net));
	    break;
      }
}

/*
 * Any Xilinx device works with this adder.
 * Generic Xilinx add only works for single bit slices.
 */
void xilinx_add(ivl_lpm_t net)
{
      const char*ha_init = 0;
      edif_cellref_t lut;
      edif_joint_t jnt;

      switch (ivl_lpm_type(net)) {
	    case IVL_LPM_ADD:
	    ha_init = "6";
	    break;
	  case IVL_LPM_SUB:
	    ha_init = "9";
	    break;
	  default:
	    assert(0);
      }

	/* If this is a single bit wide, then generate only a
	   half-adder. Normally this is an XOR, but if this is a SUB
	   then it is an XNOR. */
      if (ivl_lpm_width(net) == 1) {

	    lut = edif_cellref_create(edf, xilinx_cell_lut2(xlib));

	    jnt = edif_joint_of_nexus(edf, ivl_lpm_q(net, 0));
	    edif_add_to_joint(jnt, lut, LUT_O);

	    jnt = edif_joint_of_nexus(edf, ivl_lpm_data(net, 0));
	    edif_add_to_joint(jnt, lut, LUT_I0);

	    jnt = edif_joint_of_nexus(edf, ivl_lpm_datab(net, 0));
	    edif_add_to_joint(jnt, lut, LUT_I1);

	    edif_cellref_pstring(lut, "INIT", ha_init);
	    return;
      }

      assert(0);
}

/*
 * The left shift is implemented as a matrix of MUX2_1 devices. The
 * matrix has as many rows as the device width, and a column for each
 * select.
 */
void xilinx_shiftl(ivl_lpm_t net)
{
      unsigned width = ivl_lpm_width(net);
      unsigned nsel = 0, swid = 0;
      unsigned sdx, qdx;

      edif_cellref_t* cells;
      edif_cellref_t**table;

      edif_cellref_t pad0_cell;
      edif_joint_t pad0;


	/* First, find out how many select inputs we really need. We
	   can only use the selects that are enough to shift out the
	   entire width of the device. The excess can be used as an
	   enable for the last column. When disabled, the last column
	   emits zeros. */

      while (nsel < ivl_lpm_selects(net)) {

	    nsel += 1;

	    swid = 1 << nsel;
	    if (swid >= width)
		  break;
      }

      assert(nsel > 0);

	/* Allocate a matrix of edif_cellref_t variables. A devices
	   will be addressed by the expression table[sdx][qdx];
	   This should make the algorighm code easier to read. */
      cells = calloc(nsel * width, sizeof(edif_cellref_t));
      table = calloc(nsel, sizeof(edif_cellref_t*));

      for (sdx = 0 ;  sdx < nsel ;  sdx += 1)
	    table[sdx] = cells + sdx*width;

	/* Make a 0 valued pad bit. I wlil use this for all the shifin
	   values that are beyond the input. */
      pad0_cell = edif_cellref_create(edf, cell_0);
      pad0 = edif_joint_create(edf);
      edif_add_to_joint(pad0, pad0_cell, 0);

	/* The LUT matrix is <nsel> columns of <width> devices, with
	   the last column a LUT4 devices. The extra input of the
	   LUT4s in the last column are used as an enable to collect
	   all the excess select inputs. */

	/* Allocate the LUT devices of the matrix, and connect the
	   select inputs to I2 of all the devices of the column. */
      for (sdx = 0 ;  sdx < nsel ;  sdx += 1) {
	    const char*init_string = 0;
	    ivl_nexus_t nex = ivl_lpm_select(net,sdx);
	    edif_joint_t sdx_jnt = edif_joint_of_nexus(edf, nex);

	    edif_cell_t lut;

	    if (((sdx+1) == nsel) && (nsel < ivl_lpm_selects(net))) {
		  lut = xilinx_cell_lut4(xlib);
		  init_string = "00CA";
	    } else {
		  lut = xilinx_cell_lut3(xlib);
		  init_string = "CA";
	    }

	    for (qdx = 0 ;  qdx < width ;  qdx += 1) {
		  table[sdx][qdx] = edif_cellref_create(edf, lut);
		  edif_add_to_joint(sdx_jnt, table[sdx][qdx], LUT_I2);

		  edif_cellref_pstring(table[sdx][qdx], "INIT", init_string);
	    }
      }

	/* Connect the inputs of the SHIFTL device to the column 0 LUT
	   inputs. The slice on the low end shifts in a 0 for a select
	   input. */
      for (qdx = 0 ;  qdx < width ;  qdx += 1) {
	    ivl_nexus_t nex0, nex1;
	    edif_joint_t jnt0;
	    edif_joint_t jnt1;

	    nex0 = ivl_lpm_data(net,qdx);
	    jnt0 = edif_joint_of_nexus(edf, nex0);

	    if (qdx > 0) {
		  nex1 = ivl_lpm_data(net,qdx-1);
		  jnt1 = edif_joint_of_nexus(edf, nex1);
	    } else {
		  jnt1 = pad0;
	    }

	    edif_add_to_joint(jnt0, table[0][qdx], LUT_I0);
	    edif_add_to_joint(jnt1, table[0][qdx], LUT_I1);
      }

	/* Make the inner connections between LUT devices. Each column
	   connects to the previous column, shifted by the power of
	   the column value. If the shifted input falls off the end,
	   then pad with zero. */
      for (sdx = 1 ;  sdx < nsel ;  sdx += 1) {

	    for (qdx = 0 ;  qdx < width ;  qdx += 1) {
		  unsigned shift = 1 << sdx;
		  edif_joint_t jnt0 = edif_joint_create(edf);
		  edif_joint_t jnt1 = (qdx >= shift)
			? edif_joint_create(edf)
			: pad0;

		  edif_add_to_joint(jnt0, table[sdx][qdx], LUT_I0);
		  edif_add_to_joint(jnt1, table[sdx][qdx], LUT_I1);

		  edif_add_to_joint(jnt0, table[sdx-1][qdx], LUT_O);
		  if (qdx >= shift)
		       edif_add_to_joint(jnt1, table[sdx-1][qdx-shift], LUT_O);
	    }
      }

	/* Connect the output of the last column to the output of the
	   SHIFTL device. */
      for (qdx = 0 ; qdx < width ;  qdx += 1) {
	    ivl_nexus_t nex = ivl_lpm_q(net,qdx);
	    edif_joint_t jnt = edif_joint_of_nexus(edf, nex);

	    edif_add_to_joint(jnt, table[nsel-1][qdx], LUT_O);
      }

	/* Connect the excess select inputs to the enable inputs of
	   the LUT4 devices in the last column. */
      if (nsel < ivl_lpm_selects(net)) {
	    edif_joint_t jnt;

	      /* XXXX Only support 1 excess bit for now. */
	    assert((nsel + 1) == ivl_lpm_selects(net));

	    jnt = edif_joint_of_nexus(edf, ivl_lpm_select(net,nsel));
	    for (qdx = 0 ;  qdx < width ;  qdx += 1)
		  edif_add_to_joint(jnt, table[nsel-1][qdx], LUT_I3);
      }

      free(cells);
      free(table);
}


/*
 * $Log: xilinx.c,v $
 * Revision 1.2  2003/06/25 02:55:57  steve
 *  Virtex and Virtex2 share much code.
 *
 * Revision 1.1  2003/04/05 05:53:34  steve
 *  Move library cell management to common file.
 *
 */

