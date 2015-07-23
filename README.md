# Control-Flow-Integrity

## About This Project

This project captures research to effectively fix the lack of underlying control flow enforcement that would prevent memory corruption exploitation. This is not existent today but could be implemented in the future by the IT industry.

## Paper
[Hardware Control Flow Integrity (CFI) for an IT Ecosystem](https://github.com/iadgov/Control-Flow-Integrity/blob/master/paper/Hardware Control Flow Integrity for an IT Ecosystem.pdf)

The paper is a brief introduction to the problem of memory corruption and a description of one way to solve the cyber consequence of control flow hijacking. Then a discussion on the issues that may be encountered in the Enterprise when an architecural change like this is introduced.
 
Any quesions or discussion can be sent by Email to control-flow-integrity@nsa.gov or open an [issue via GitHub tracker](https://github.com/iadgov/Control-Flow-Integrity/issues/new).

## Code 

The [code folder](https://github.com/iadgov/Control-Flow-Integrity/tree/master/code) has actual binary implementations of SW that would leverage the HW described in the paper. It is hoped that researchers can learn more about the effect and strength of this technique by reverse engineering and perhaps doing some form of static analysis on them. The files are:

* 2 source files having a buffer overflow of either a return address or a function pointer. (stack-return.c and stack-functionptr.c)
* 2 Linux binaries that were compiled with new landing point opcodes. (stack-return and stack-functionptr)
* 2 instrumented Linux libraries that were linked to the example buffer overflow binaries.(ld-linux-x86-64.so.2 and libc.so.6)
* 1 binary of a typical linux utility that has been instrumented with landing point opcodes.

With these simple examples, one can get started to see the impact of the CFI countermeasure in an entire address space.

In the future we should be releasing more tools to enable researchers to reproduce their own binaries. This would include things like compiler extensions and perhaps full-runtimes that would work in an emulator such as QEMU. Also research results.


## License
This work was prepared by an U.S. Government employee and, therefore, is excluded from copyright by Section 105 of the Copyright Act of 1976.

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

