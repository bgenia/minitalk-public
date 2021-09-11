SRC_CLIENT := \
	src/client/signal_status/status_set_processed.c \
	src/client/signal_status/status_set_received.c \
	src/client/signal_status/status_clear.c \
	src/client/signal_status/status_await.c \
	src/client/signal_status/signal_status.c \
	src/client/send_message.c \
	src/client/signal_handling/handle_status.c \
	src/client/signal_handling/register_signal_handers.c \
	src/client/main.c \

SRC_SERVER := \
	src/server/output/get_output_stream.c \
	src/server/server_loop.c \
	src/server/signal_handling/register_signal_handlers.c \
	src/server/signal_handling/handle_interrupt.c \
	src/server/signal_handling/handle_data.c \
	src/server/main.c \
