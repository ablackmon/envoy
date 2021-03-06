#include "test/integration/protocol_integration_test.h"

namespace Envoy {

// For tests which focus on downstream-to-Envoy behavior, and don't need to be
// run with both HTTP/1 and HTTP/2 upstreams.
INSTANTIATE_TEST_SUITE_P(Protocols, DownstreamProtocolIntegrationTest,
                         testing::ValuesIn(HttpProtocolIntegrationTest::getProtocolTestParams(
                             {Http::CodecClient::Type::HTTP1, Http::CodecClient::Type::HTTP2},
                             {FakeHttpConnection::Type::HTTP1})),
                         HttpProtocolIntegrationTest::protocolTestParamsToString);

INSTANTIATE_TEST_SUITE_P(Protocols, ProtocolIntegrationTest,
                         testing::ValuesIn(HttpProtocolIntegrationTest::getProtocolTestParams()),
                         HttpProtocolIntegrationTest::protocolTestParamsToString);

} // namespace Envoy
