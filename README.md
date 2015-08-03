# Control Flow Integrity

## About This Project

This project captures research to effectively fix the lack of underlying control flow enforcement that would prevent memory corruption exploitation. This mechanism does not exist today but could be implemented in the future by the IT industry.

## Paper

Hardware Control Flow Integrity (CFI) for an IT Ecosystem
* [Download PDF](https://github.com/iadgov/Control-Flow-Integrity/raw/master/paper/Hardware Control Flow Integrity for an IT Ecosystem.pdf)
* [View PDF on GitHub](https://github.com/iadgov/Control-Flow-Integrity/blob/master/paper/Hardware Control Flow Integrity for an IT Ecosystem.pdf)

This paper is a brief introduction to the problem of memory corruption and a description of one way to prevent control flow hijacking. It also includes a discussion on the issues that may be encountered in the IT ecosystem when an architectural change like this is introduced.
 
Questions or comments can be sent to control-flow-integrity@nsa.gov or [submitted](https://github.com/iadgov/Control-Flow-Integrity/issues/new) to [our GitHub issue tracker](https://github.com/iadgov/Control-Flow-Integrity/issues).

## Code 

The [code folder](https://github.com/iadgov/Control-Flow-Integrity/tree/master/code) has examples of software that would leverage the hardware described in the paper. It is hoped that researchers can learn more about the effect and strength of the proposal by reverse engineering and performing static analysis on them. Perhaps demonstrate a way to bypass the mitigation and report via mechanisms described above. The files are:

* 2 source files that have a buffer overflow of either a return address or a function pointer (i.e. stack-return.c and stack-functionptr.c).
* 2 Linux binaries of the overflow source files instrumented with new landing point opcodes (i.e. stack-return and stack-functionptr).
* 2 instrumented Linux libraries that were linked to the example buffer overflow binaries (ld-linux-x86-64.so.2 and libc.so.6).
* 1 binary of ls, just as a typical Linux utility that has been instrumented with landing point opcodes.

These simple examples should allow one to explore the impact of the CFI countermeasure in a process address space. The binaries should run on any x86 Linux machine. The opcodes will work as NOP's. The landing point opcodes are as follows:

* CLP: 0x0f,1f,40,aa
* JLP: 0x0f,1f,40,bb
* RLP: 0x0f,1f,40,cc

The binaries contain no fine grained label checks. They only have a corresponding Landing Point instruction to any indirect branch as a label, which is coarse grained. If other binaries are desired, we can produce them, if source is provided.

One can extract the gadgets (as defined on line 271/2 in the paper) from the binaries and attempt to chain them together. Note: RLP gadgets are of no semantic use due to the (imaginary) shadow stack. So gadget chains can only contain CLP and JLP based gadgets. To test validity of a claim, one can use gdb to "run" a gadget chain. First one can manually change the memory as an exploit might do by setting a breakpoint at the appropriate place and performing the overwrite(s). Then continue using single stepping. As a substitute for the HW enforcement, whenever an indirect branch occurs one can visually validate it lands on a landing point. If it reaches the goal (e.g. exec("Your string")) without crashing the application, you win and this form of CFI loses. There is no secret right answer. We believe it's not possible or extremely unreliable to bypass the minimal CFI design (line 116 in the paper) with these code samples (and others like them). Unfortunately, this is the best dynamic tool we can offer for now to allow independent validation.

In the future we will be releasing research results quantifying the strength and weakness of the proposal as well as possibly releasing tools to enable researchers to produce and run their own binaries. These tools would include items such as compiler extensions, QEMU extensions and full OS runtimes that would work in QEMU. The tools used to create the current code repository are fragile but getting better.

## License
This work was prepared by an U.S. Government employee and, therefore, is excluded from copyright by Section 105 of the Copyright Act of 1976.

Copyright and Related Rights in the Work worldwide are waived through the [CC0 1.0](https://creativecommons.org/publicdomain/zero/1.0/) [Universal license](https://creativecommons.org/publicdomain/zero/1.0/legalcode).

## Disclaimer
This Work is provided "as is." Any express or implied warranties, including but not limited to, the
implied warranties of merchantability and fitness for a particular purpose are disclaimed. In no event
shall the United States Government be liable for any direct, indirect, incidental, special, exemplary or
consequential damages (including, but not limited to, procurement of substitute goods or services, loss
of use, data or profits, or business interruption) however caused and on any theory of liability, whether
in contract, strict liability, or tort (including negligence or otherwise) arising in any way out of the use of
this Guidance, even if advised of the possibility of such damage.

The User of this Work agrees to hold harmless and indemnify the United States Government, its agents
and employees from every claim or liability (whether in tort or in contract), including attorneys' fees,
court costs, and expenses, arising in direct consequence of Recipient's use of the item, including, but not
limited to, claims or liabilities made for injury to or death of personnel of User or third parties, damage
to or destruction of property of User or third parties, and infringement or other violations of intellectual
property or technical data rights.

Nothing in this Work is intended to constitute an endorsement, explicit or implied, by the U.S.
Government of any particular manufacturer's product or service.