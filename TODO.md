#List of TODO items for SIMD

# SIMD TODO #

Below is a prioritized list of the items that have to be implemented/fixed in SIMD. To get more context on why certain things are needed, you might want to look at the wiki page on SIMD [History](History.md)


## CORE ##
# **PIMPL Idiom**. The PIMPL idiom is used in SIMD to decouple the ISO C++ API for DDS with implementations coming from various vendors. However not all the class are currently built using the PIMPL idiom. One very much needed re-factoring is to apply the PIMPL idiom to classes in which it is not currently used.

# **Pre/Post Conditions**. Pre/Post conditions are not currently used in a very uniform manner. These should be added to all the SIMD method. Notice that there is already an assertion class.

## API ##


## Tutorial ##
# **Getting Started with SIMD**. It'd be very good if someone could contribute a Getting Started tutorial for SIMD.

## Code Documentation ##
# **Class/Method Docs**. SIMD APIs implement DDS API as such the ultimate documentation is the DDS Specification. However it'd be good to add some more class documentation describing exactly whatever the standard says. This would make it easier for people that are not familiar with the DDS standard to get started.