#ifndef AC_SIMD_DDS_RUNTIME_IMPL_HPP_
#define AC_SIMD_DDS_RUNTIME_IMPL_HPP_

// -- STD C++ Include
#include <string>

// -- Boost Includes
#include <boost/shared_ptr.hpp>

#include <dds/domain.hpp>
// #include <dds/publisher.hpp>
// #include <dds/subscriber.hpp>

namespace dds {
  class Publisher;
  class Subscriber;

  namespace peer {

    class SIMD_EXPORT RuntimeImpl {

  public:
    static const std::string DEFAULT_DOMAIN;
    static const std::string DEFAULT_PARTITION;

  public:
    static void start();
    static void start(const std::string& partition);
    static void start(const std::string& partition, const std::string& domain);
    /*
      static void start(std::ifstream& is);

      static void start(const std::string& domain,
      const DDS::DomainParticipantQos& qos);
    */
    static void stop();

  protected:
    RuntimeImpl();
    RuntimeImpl(const std::string& domain);
    void init(const std::string& partition);
  public:
    ~RuntimeImpl();

  public:

    static RuntimeImpl* instance() throw ();

    // TODO: Implement this method1
    //  void set_listener(shared_ptr<DDS::DomainParticipantListener> listener);

    //@TODO: Provide SIMD_DDS facades to the DomainParticipant, Publisher, Subscriber, etc.
    /**
     * Get the default participant.
     */
    ::dds::DomainParticipant get_participant() throw ();

    /**
     * Get the default publisher.
     */
    // boost::shared_ptr<DDS::Publisher> get_publisher()  throw ();
    dds::Publisher get_publisher()  throw ();

    /**
     * Get the default subscriber.
     */
    dds::Subscriber get_subscriber()  throw ();

  private:
    static RuntimeImpl* this_;

    ::dds::DomainParticipant dp_;

    dds::Publisher* pub_;
    dds::Subscriber* sub_;
    //    boost::shared_ptr<DDS::Publisher> pub_;
    //    boost::shared_ptr<DDS::Subscriber> sub_;

  };

  } 
}
#endif /* AC_SIMD_DDS_RUNTIME_IMPL_HPP_ */