Info
------------
- This is my base in C++, I am working on my project for more simple to complex in step by step. 
So it is heavily in WIP :).

Cloning
-------------
The actual source code is contained one repository (Fujiyama renderer) referenced here as git submodules.

Type as : git clone --recurse-submodules https://github.com/threedslider/blackdot-cc.git

Blackdot
-------------

Blackdot is the free and open source 3D creation suite and it greatly is inspired from Softimage XSI.
It works as wip the entirety of coming to later : the 3D pipeline-modeling, rigging, animation, simulation,
rendering, compositing, motion tracking and video editing.


Plan for adding/improving to Blackdot
-------------

- [] UI from Softimage XSI (Wip)
- [] Tools in 3D modeling (based on Softimage XSI) (Wip)
- [] OOM (Oriented Object Modeling)
- [] Metamesh modeling
- [] Sculpting 3D
- [] Animation and rigging
- [] ICE system (based inspiration from geomety nodes)
	- [] Particles
	- [] Deform
	- [] Kinematic
	- [] CrowdFX
- [] Hair system
- [] Fluid simulation
- [] Advanced 3D painting
- [] New NPR shading
- [] 3D Rendending : Fujiyama renderer and his improvement later
- [] 3D Tracking
- [] Cloth system
- [] Soft and rigid body system
- [] Advanced VFX compositing
- [] Advanced video editor 
- [] Support to Python scripting
- [] Support to AngelScript
- [] Editor scripting


Development
-------------

It will support to Vulkan.

It will support to AngelScript and Python.

It will be written in C++.


Author
-------------

Laurent Le Flem (Main author)


License
-------------

Blackdot as a whole is licensed under the GNU General Public License, Version 3.


Thanks
-------------

- Blackdot give to tribute at Daniel Langlois and I thank much at him the creator of Softimage, a 3d software loved by a lot of 3d Artists around the world. 
I am inspired by him and hope I will bright to you for your enjoy with this Blackdot too in 3D.



== Faq ==
-------------


Where is the official site of Blackdot ?
-------------

  The official site of Blackdot is: (Wip)

  [Mospixel](https://www.mospixel.com)



Where can i find a tutorial for Blackdot ?
-------------

  There is no tutorial. It is in WIP coming to later when it will be ready :-)


What is Global Illumination ?
-------------

See [here](https://en.wikipedia.org/wiki/Global_illumination) for more explanation.


Is it possible to write new modules or plug-ins ?
-------------

  The kernel of Blackdot is not yet currently being written. This soon new
  architecture will allow:
  -  + plug-ins in Python and Angelscript
  -  + multiple material type, multiple renderer to be used
  -  + multiple kinds of GUI's.
  -  + Tools for modelling and other stuffs.


Do you plan to integrate shaders into the Blackdot renderer ?
-------------

  Why not! Based on Fujiyama Renderer, I will bright more shaders and create one on your own as well.


Do you plan to write a GTK+ or QT GUI for Blackdot ?
----------------------------------------------------------------------------

  No, The architecture that i am currently writing is by me (WIP) and powered with OpenGL and Vulkan.
   (Watch to the soon at the gui_xsi directory)


