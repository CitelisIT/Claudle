import { UserCircleIcon } from "@heroicons/react/outline";
import { useForm, SubmitHandler } from "react-hook-form";
import React from "react";
import axios from "axios";
import { useNavigate } from "react-router-dom";

type Inputs = {
  username: string;
  password: string;
  passwordConfirm: string;
};

export default function RegisterForm() {
  const navigate = useNavigate();
  const {
    register,
    handleSubmit,
    formState: { errors },
    watch,
  } = useForm<Inputs>();
  const onSubmit: SubmitHandler<Inputs> = (data) => {
    axios
      .post("/api/register", {
        username: data.username,
        password: data.password,
      })
      .then((response) => {
        if (response.status === 200) {
          const respData = response.data;
          sessionStorage.setItem("token", respData.token);
          navigate("/");
        }
      })
      .catch((error) => {
        console.log(error);
      });
  };
  const pwd = watch("password", "");

  return (
    <div className="flex flex-col items-center justify-center w-full gap-16 p-12 md:p-16">
      <div className="flex flex-col items-center justify-center gap-8">
        <UserCircleIcon className="w-10 h-10 text-gray-200 lg:h-12 lg:w-12" />
        <span className="text-base font-semibold text-gray-200 md:text-lg lg:text-xl">
          Créer un compte
        </span>
      </div>
      <form
        onSubmit={handleSubmit(onSubmit)}
        className="flex flex-col items-start justify-center w-10/12 gap-8 text-gray-200 lg:w-5/12"
      >
        <fieldset className="w-full">
          <label
            htmlFor="username-input"
            className="text-base font-medium lg:text-xl md:text-lg"
          >
            Nom d'utilisateur
          </label>
          <input
            {...register("username", { required: true })}
            name="username"
            id="username-input"
            className="w-full p-2 py-2 bg-gray-900 border border-gray-600 rounded-lg md:my-4"
          />
          {errors.username ? (
            <p className="form-error">Veuillez entrer un nom d'utilisateur</p>
          ) : (
            <></>
          )}
        </fieldset>
        <fieldset className="w-full">
          <label
            htmlFor="pwd-input"
            className="text-base font-medium lg:text-xl md:text-lg"
          >
            Mot de passe
          </label>
          <input
            type="password"
            {...register("password", { required: true })}
            name="password"
            id="pwd-input"
            className="w-full p-2 py-2 bg-gray-900 border border-gray-600 rounded-lg md:my-4"
          />
          {errors.password ? (
            <p className="form-error">Veuillez entrer un mot de passe</p>
          ) : (
            <></>
          )}
        </fieldset>
        <fieldset className="w-full">
          <label
            htmlFor="pwd-bis-input"
            className="text-base font-medium lg:text-xl md:text-lg"
          >
            Répéter le mot de passe
          </label>
          <input
            type="password"
            {...register("passwordConfirm", {
              required: true,
              validate: (value) =>
                value === pwd || "Les mots de passe ne sont pas identiques",
            })}
            name="passwordConfirm"
            id="pwd-bis-input"
            className="w-full p-2 py-2 bg-gray-900 border border-gray-600 rounded-lg md:my-4"
          />
          {errors.passwordConfirm ? (
            <p className="form-error">{errors.passwordConfirm.message}</p>
          ) : (
            <></>
          )}
        </fieldset>
        <div className="flex items-center justify-end w-full">
          <button
            onClick={handleSubmit(onSubmit)}
            className="p-2 text-base text-green-600 border border-green-600 rounded-lg md:text-lg lg:text-xl"
          >
            Créer un compte
          </button>
        </div>
      </form>
    </div>
  );
}
