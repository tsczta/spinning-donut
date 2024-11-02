# spinning-donut
Motivation

  In my first and second years of high school, I did self-study on topics like probability and the C++ programming language. However, all of this learning was through online courses. Although I learned a lot, none of it was something I created by myself. This reminded me of a video I watched on YouTube back in junior high, before I even started learning programming: "Why You NEED Math for Programming." The video introduced a program that left a lasting impression on me—a spinning 3D donut. I wanted to create something that I had previously thought was beyond my reach, so I decided to make it the focus of my self-study.

Learning Process

  I searched online for information on how to create this program, but I encountered several challenges. Many of the websites I found were in English, which made them difficult to read. Some sites had shallow, repetitive content that only copy-pasted code from elsewhere.The repeated code across different sites and unfamiliar English vocabulary made reading challenging. As a result, I felt the project wasn’t progressing smoothly, and I didn’t know where to start. I decided to try designing the code on my own without relying on online resources. Yet, when I tried to start coding, I couldn’t figure out where to begin. After staring at a blank screen for a while, I only managed to write a program that could display a circle.After this initial failure, I decided to go back to the English websites I’d previously abandoned. This time, I read slowly and used online tools to translate whenever I encountered difficulty. Although some translations were illogical, breaking down the vocabulary helped me understand most of the content. Before designing the code, I learned from the site what concepts I needed to study and what steps to take to build the program, using this to create my self-study plan.

My Plan

  Since the program involved mathematical formulas like dot products and rotation matrices, I looked up proofs and went through them myself.

Reference Derivations

  After understanding these, I began coding on my computer. I made many mistakes along the way, which resulted in various unexpected errors, such as:

•Parameter errors causing unexpected negative brightness values.

•A donut with missing sections and reversed lighting.

•Forgetting to clear the old image.

When I encountered these issues, I carefully reviewed my code and found that the negative brightness was due to overlooked type conversions, the reversed lighting was caused by errors in converting between arrays and coordinates, and the leftover image was resolved by adding system("cls") to clear the screen. Debugging felt rewarding as I moved step-by-step closer to completing the project. Finally, after multiple rounds of trial and error, I completed the code!

Program explanation
  The final code mainly consists of five functions—reset(), rotate(), projection(), calculate(), and print()—and a continually running while loop.

Variables:

•z_buffer: Stores the closest projected position and brightness in the current space.

•R1: The radius of the donut.

•R2: The thickness of the donut.

•K1: Distance between the screen and observer.

•K2: Distance between the donut and observer.

•A, B: Rotation angles.

Functions:

•reset(): Resets the data in z_buffer to prevent interference from previous calculations as the while() loop runs continuously.

•rotate(): Continuously updates angles A and B to match the current rotation.

•projection(): Projects calculated positions onto z_buffer based on depth and brightness.

•calculate(): Computes the current angle and brightness of the donut based on A and B.

•print(): Determines and prints the symbols on the screen based on z_buffer calculations.

While Loop:

The while loop integrates the previous functions. It first uses system("cls") to clear the screen, resets the z_buffer data, updates angles A and B, calculates new positions and brightness, and finally prints the donut!

Reflection

  Through this self-study project, I learned about concepts like dot products and rotation matrices and improved my debugging skills during the coding process. What left the deepest impression on me was the feeling of looking up information, thinking through the design, coding by hand, troubleshooting, and finally finishing this project. This experience brought back the excitement I felt when I first started learning programming, and it made me look forward even more to creating unique and special programs in the future.
