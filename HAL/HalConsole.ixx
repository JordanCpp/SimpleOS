
module;

export module HAL.IConsole;

export namespace HAL
{
	class IConsole
	{
	public:
		virtual ~IConsole() = default;
		virtual void Clear() noexcept = 0;
		virtual void Write(char c) noexcept = 0;
		virtual void Write(const char* src) noexcept = 0;
	};
}
