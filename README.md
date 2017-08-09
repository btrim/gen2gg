# gen2gg


### Use a Genesis / Mega Drive Controller to control Game Gear games.
----

#### Disclaimer

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#### Requirements
  * Arduino UNO or compatible.  I think (but don't know 100%) the GG uses 5V logic, and so you'll want an arduino that uses 5V.  If this causes excessive heat or damage to your GG, Arduino, or controller, see the disclaimer above.
  
  * A modified Game Gear with the ability to wire Up, Down, Left, Right, 1, 2, and Start to the Arduino.  Start should output high on pin 7 to allow for unmodified genesis controllers to work (without pause).

#### Instructions

  1. Connect the GG inputs to the following arduino pins
  
     | GG Input   |  Arduino Pin    |
     |:------:|:------:|
     |UP|A5|
     |DOWN|A4|
     |LEFT|A3|
     |RIGHT|A2|
     |ONE|A1|
     |TWO|A0|
     |START|13*|
     
     *13 is the LED pin on an Arduino UNO, so you may want to change this in the code and use another to avoid leaving this LED blinking off when start is pressed.
     
  2. Connect the Genesis / Mega Drive Inputs and outputs.
  
     | Controller | Arduino Pin |
     |:----:|:---:|
     |UP|2|
     |DOWN|3|
     |LEFT|4|
     |RIGHT|5|
     |B/A|6|
     |C/START|7|
     |SELECT|8|
