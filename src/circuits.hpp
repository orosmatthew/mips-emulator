#ifndef MIPS_EMULATOR_CIRCUITS_HPP
#define MIPS_EMULATOR_CIRCUITS_HPP

typedef char bit;
typedef bit bin_val[32];

struct adder_output
{
    bit sum;
    bit carry;
};

bit and_gate(const bit a, const bit b)
{
    if (a == 1 && b == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bit or_gate(const bit a, const bit b)
{
    if (a == 1 || b == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bit not_gate(const bit b)
{
    if (b == 1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

bit or3_gate(const bit a, const bit b, const bit c)
{
    if (or_gate(or_gate(a, b), c) == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bit or4_gate(const bit a, const bit b, const bit c, const bit d)
{
    if (or_gate(or3_gate(a, b, c), d) == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bit and3_gate(const bit a, const bit b, const bit c)
{
    if (and_gate(and_gate(a, b), c) == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bit and4_gate(const bit a, const bit b, const bit c, const bit d)
{
    if (and_gate(and3_gate(a, b, c), d) == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bit and5_gate(const bit a, const bit b, const bit c, const bit d, const bit e)
{
    if (and_gate(and4_gate(a, b, c, d), e) == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bit mux_2to1(const bit a, const bit b, const bit s)
{
    bit and_g0 = and_gate(a, not_gate(s));
    bit and_g1 = and_gate(b, s);
    bit or_g0 = or_gate(and_g0, and_g1);
    return or_g0;
}

bit mux_4to1(const bit a, const bit b, const bit c, const bit d, const bit s1, const bit s2)
{
    bit mux0 = mux_2to1(a, b, s1);
    bit mux1 = mux_2to1(c, d, s1);
    bit mux2 = mux_2to1(mux0, mux1, s2);
    return mux2;
}

adder_output full_adder_sum(const bit a, const bit b, const bit carry_in)
{
    bit and3_g0 = and3_gate(not_gate(a), not_gate(b), carry_in);
    bit and3_g1 = and3_gate(not_gate(a), b, not_gate(carry_in));
    bit and3_g2 = and3_gate(a, not_gate(b), not_gate(carry_in));
    bit and3_g3 = and3_gate(a, b, carry_in);
    bit or4_g0 = or4_gate(and3_g0, and3_g1, and3_g2, and3_g3);

    bit and_g0 = and_gate(a, b);
    bit and_g1 = and_gate(b, carry_in);
    bit and_g2 = and_gate(a, carry_in);
    bit or3_g0 = or3_gate(and_g0, and_g1, and_g2);

    return {or4_g0, or3_g0};
}


void sign_ext(bin_val* bin_val, const bit* ptr)
{
    for (int i = 0; i < 16; i++)
    {
        (*bin_val)[i] = ptr[0];
    }
    for (int i = 16; i < 32; i++)
    {
        (*bin_val)[i] = ptr[i - 16];
    }
}

#endif //MIPS_EMULATOR_CIRCUITS_HPP
