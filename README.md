## 🖥️ General Information

The goal of this project is to create a fractal renderer.

### Subject's Requirements

  --> We have to the school's graphical library : **Minilibx**
  
  --> Render the **Mandelbrot** set and the **Julia** set
  
  --> Handle basic events such as closing the renderer's window, zooming in and out, moving the view etc.. 

## 🧠 What is a fractal ? 

A fractal is a complex pattern that looks similar at different scales. 
This means that if you zoom in on a fractal, you'll see smaller versions of the same pattern repeating over and over. 
Fractals can be found in nature, like in snowflakes, mountains, and coastlines, as well as in mathematical shapes.

In order to understand how to render fractal, we have to look at the notion of complex numbers.
Complex numbers are a type of number that expands our understanding of numbers beyond the regular ones we use every day, like whole numbers, fractions, and decimals.

A complex number has two parts: a real part and an imaginary part. It is usually written in the form:
```
a + bi
```
Here:

  **a** is the real part (a regular number).
  **b** is the imaginary part (also a regular number).
  **i** is a special symbol that represents the square root of -1. This means that when you multiply i by itself (i.e., i × i), you get -1.

For example, in the complex number 3 + 4i:

  **3** is the real part.
  **4** is the imaginary part.

Using different formulas of complex number, we can render different types of fractal shapes. 
For example, the Mandelbrot set formula which we have to render in this project is :
```
 Z n + 1 = Z n 2 + Z 0
```

## 📌 File Organisation

The file organisation is pretty self explanatory. 

  **mlx_init.c** --> Initializes all the variable required by minilibx to open a window.
  
  **handle_params.c** --> Parses the parameters sent to the program and initializes the structure with the name of the fractal to render. 
  
  **handle_events.c** --> Initializes and infinite loop that waits for events to happen a render the fractal as a consequences of those events. Events include clicking on the mouse or on a key.
  
  **handle_colors.c** --> Depending on the parameters send to the programms, applies different colors sets. 
  
  **mandelbrot.c** --> compute and draws the Mandelbrot set on an image. 
  
  **julia.c** --> compute and drwas the Julia set on an image. 
  
  **atod.c** --> Converts and character into a double.
  
  **main.c**

Most of these files have a _bonus version which adds more sets of colors and the possibility to zoom in and out not only in the middle of the window but where the mouse is placed.

  **burningship_bonus.c** --> An additional fractal that is computed and drawn into the window called the burning ship. 

## 🖌️ Coloring

In order to dinstinguish the details of the fractal we use an escape-time algorithm. It helps to determine how quickly points in a certain area "escape" to infinity when a specific mathematical operation is applied repeatedly.

Here’s how it works in simple terms:

  **Pick a Point**: You start with a point in the complex plane (which is a way of visualizing complex numbers).

  **Apply a Formula**: You use a mathematical formula (often involving complex numbers) to see what happens to that point when you apply the formula over and over again.

  **Check for Escape**: You keep applying the formula until the point either escapes to infinity (meaning it gets really, really big) or you decide it’s not going to escape after a certain number of tries.

  **Color the Point**: If the point escapes quickly, you can color it one way; if it takes longer to escape, you can use a different color. Points that don’t escape at all can be colored differently, too.

## 📁 Installation

The repository contains all the needed libraries to work under **Linux**. Clone the project into your working directory.
```
git clone <repository_url>
```

Use the make or make bonus command and run the programm with the following arguments. 
```
./fractol [fractal type] [fractal color] (julia real) (julia imaginary)
```

For example if you want to render a grey Mandelbrot Set type :
```
./fractol m grey
```
The fractal types are : 
  - Mandelbrot (m)
  - Julia (j)
  - If make bonus installed, burning ship (b)

**If you decide to render a Julia set, to enter a real and imaginary between -2 and 2.**
Here is an example for an intresting Julia set :
```
./fractol j rainbow 0.285 0.01
```

The set of colors available are :
  - red
  - rainbow
If make bonus installed you can also choose :
  - blue
  - grey

If make bonus is installed, press the key **'C'** to change the color of the fractal, press the key **'F'** to alternate between the Mandelbrot set and the Burning Ship fractal.

## 📷 Screenshots

| <img src = "https://github.com/lgernido/fractol/blob/main/Screenshots/Screenshot%20from%202024-11-19%2013-58-07.png"> |<img src = "https://github.com/lgernido/fractol/blob/main/Screenshots/Screenshot%20from%202024-11-19%2014-03-34.png" >|
|----------------------------------------------|----------------------------------------------|
| Mandelbrot Set                               | Julia Set                                    |

| <img src = "https://github.com/lgernido/fractol/blob/main/Screenshots/Screenshot%20from%202024-11-19%2014-04-04.png" >|<img src = "https://github.com/lgernido/fractol/blob/main/Screenshots/Screenshot%20from%202024-11-19%2014-05-39.png" >|
|----------------------------------------------|----------------------------------------------|
| Burning Ship                                 | Zoomed in Julia Set                          |

## Additional Ressources

🇫🇷

Arte - Pique Nique sur le plan complexe - (https://www.youtube.com/watch?v=M6o5CRYfNxA)

🇬🇧

Rendering Fractals - (https://www.youtube.com/watch?v=wUlVFYJIUNA)

An Introduction to shader art coding - (https://www.youtube.com/watch?v=M6o5CRYfNxA)
