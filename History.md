#This page summarize the history of SIMD

# SIMD's History #

SIMD was started as an experiment that I hacked non-stop over a sleepless night. My original intent was to have an API that was nicer to use and see how simple I could get it. After a night hacking code by my large window facing the Chevreuse Valley Forest (http://www.vallee-de-chevreuse.com/) I was very happy with the API. The API was good and was working as a result people started using it and I started popularizing it within the OMG as a candidate for the new DDS C++ PSM.

As a result I decided that SIMD could really become what CZed used to be (see czed.sourceforge.net), meaning the incubator for the new C++ API for DDS. The key advantage of SIMD over CZED were that SIMD could run on OpenSplice DDS while CZed was just an API w/o implementation. In addition, when doing CZed I had been less extreme in re-designing the API since I did not want to impact too much the DDS PIM. The one disadvantage is that SIMD has to deal with a real DDS implementation, thus there are some types that I can't quite change unless I hack the IDL compiler for the DDS implementation or I introduce copies etc.

SIMD is thus evolving toward the new ISO standard C++ API for DDS and as a result its core is being re-factored to make it simple to "plug" various vendor implementation of the API. This re-factoring is taking place now, does not require much work but recently I've been spending more times on flights than at the keyboard.


If you want to contribute to SIMD, please see the [TODO](TODO.md) list.